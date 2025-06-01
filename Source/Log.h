#include <stdio.h>

#define STATIONS_AMOUNT 7 // Number of stations
#define REG_AMOUNT 32     // Number of FP registers

char *LOG_PATH = "./out/sum_69_0.md";
void newCicle(int cicle, char *path)
{
    LOG_PATH = path;
    FILE *file = fopen(LOG_PATH, "a");
    if (file == NULL)
    {
        printf("[LogError] Invalid log path! - fn newCicle()");
    }
    else
    {
        printf("\n\033[0;36m# Cicle %d\033[0m\n", cicle);
        fprintf(file, "# CICLE %d\n## Log\n", cicle);
    }
    fclose(file);
}

/**
 * @brief TODOBRIEF
 *
 * @param step Current step 0..3; Where it means (in order): `Dispatch`, `Started`, `Completed` and `Wrote in Memory`
 */
void logInstructionStep(int step, int line)
{
    FILE *file = fopen(LOG_PATH, "a");
    if (file == NULL)
    {
        printf("[LogError] Invalid log path! - fn newCicle()");
    }
    else
    {
        switch (step)
        {
        case 0:
            printf("* \033[32m[%d]\033[0m Dispatched\n", line);
            fprintf(file, "* [%d] Dispatched\n", line);
            break;
        case 1:
            printf("* \033[32m[%d]\033[0m Started\n", line);
            fprintf(file, "* [%d] Started\n", line);
            break;
        case 2:
            printf("* \033[32m[%d]\033[0m Completed\n", line);
            fprintf(file, "* [%d] Completed\n", line);
            break;
        case 3:
            printf("* \033[32m[%d]\033[0m Wrote in memory\n", line);
            fprintf(file, "* [%d] Wrote in memory\n", line);
            break;
        default:
            printf("* \033[32m[%d]\033[0m Unknown\n", line);
            fprintf(file, "* [%d] Unknown\n", line);
            break;
        }
    }
    fclose(file);
}

void logDependencyRegister(int dependency, int line)
{
    FILE *file = fopen(LOG_PATH, "a");
    if (file == NULL)
    {
        printf("[LogError] Invalid log path! - fn newCicle()");
    }
    else
    {
        fprintf(file, "* [%d] Cannot start, it's waiting for Register %d\n", line, dependency);
        printf("* \033[32m[%d]\033[31m Cannot start\033[0m - Waiting for register %d\n", line, dependency);
    }
    fclose(file);
}

void logDependecy(int line)
{
    FILE *file = fopen(LOG_PATH, "a");
    if (file == NULL)
    {
        printf("[LogError] Invalid log path! - fn newCicle()");
    }
    else
    {
        printf("* \033[32m[%d]\033[31m Cannot be dispatched\033[0m - Waiting for a station to be free\n", line);
        fprintf(file, "* [%d] Cannot be dispatched, waiting for a station to be free\n", line);
    }
    fclose(file);
}

void logRegisters(Register registers[REG_AMOUNT], Station stations[STATIONS_AMOUNT])
{
    FILE *file = fopen(LOG_PATH, "a");
    if (file == NULL)
    {
        printf("[LogError] Invalid log path! - fn newCicle()");
    }
    else
    {
        fprintf(file, "\n## Registers\n```json\n[\n");
        printf("\n");
        for (int i = 0; i < REG_AMOUNT; i++)
        {
            if (i % 4 != 3)
            {
                printf("\x1b[33m[R%02d]: %s, value: %d \x1b[0m    ",
                       i,
                       registers[i].busyBy == -1 ? "\x1b[32mfree" : "\x1b[31mbusy",
                       registers[i].value);
            }
            else
            {
                printf("\x1b[33m[R%02d]: %s ,value: %d \x1b[0m    \n",
                       i,
                       registers[i].busyBy == -1 ? "\x1b[32mfree" : "\x1b[31mbusy",
                       registers[i].value);
            }

            if (registers[i].busyBy != -1)
            {
                fprintf(file, "{\"id\": %d, \"busyByStation\": %d, \"busyByInst\": %d, \"v\": %d},\n", i, registers[i].busyBy, stations[registers[i].busyBy].debugInstructionLine, registers[i].value);
            }
        }
        fprintf(file, "]\n```\n");
    }
    fclose(file);
}

void logStationsDetailed(Station stations[STATIONS_AMOUNT], Register registers[REG_AMOUNT])
{
    FILE *file = fopen(LOG_PATH, "a");
    if (file == NULL)
    {
        printf("[LogError] Invalid log path! - fn logStationsDetailed()\n");
        return;
    }

    fprintf(file, "\n## Reservation Stations\n");
    fprintf(file, "| Name | Busy | Op | Vj | Vk | Qj | Qk | A |\n");
    fprintf(file, "|------|------|----|----|----|----|----|---|\n");

    printf("\n\033[36mReservation Stations:\033[0m\n");
    printf("| %-6s | %-4s | %-4s | %-4s | %-4s | %-4s | %-4s | %-20s |\n", "Name", "Busy", "Op", "Vj", "Vk", "Qj", "Qk", "A");
    printf("|--------|------|------|------|------|------|------|----------------------|\n");

    // Contadores por tipo para nomear estações
    int typeCount[4] = {0}; // Load, Store, Adder, Multiplier

    for (int i = 0; i < STATIONS_AMOUNT; i++)
    {
        if (!stations[i].busy)
            continue;

        Instruction *inst = &stations[i].instruction;
        char name[10] = "";

        // Atualiza contagem e nomeia a estação corretamente
        int index = 0;
        const char *prefix = "RS";
        switch (stations[i].type)
        {
        case Load:
            prefix = "Load";
            index = ++typeCount[0];
            break;
        case Store:
            prefix = "Store";
            index = ++typeCount[1];
            break;
        case Adder:
            prefix = "Add";
            index = ++typeCount[2];
            break;
        case Multiplier:
            prefix = "Mult";
            index = ++typeCount[3];
            break;
        default:
            prefix = "RS";
            index = i;
            break;
        }
        snprintf(name, sizeof(name), "%s%d", prefix, index);

        char op[5], vj[10] = "", vk[10] = "", qj[10] = "", qk[10] = "", A[30] = "";

        // Decodifica operação
        switch (inst->operation)
        {
        case LW:
            strcpy(op, "LW");
            break;
        case SW:
            strcpy(op, "SW");
            break;
        case ADD:
            strcpy(op, "ADD");
            break;
        case SUB:
            strcpy(op, "SUB");
            break;
        case MUL:
            strcpy(op, "MUL");
            break;
        case DIV:
            strcpy(op, "DIV");
            break;
        default:
            strcpy(op, "???");
            break;
        }

        if (inst->type == TwoReg)
        {
            int baseReg = inst->twoReg.srcReg1;
            int offset = inst->twoReg.offset;

            if (isRegisterFree(registers[baseReg], i))
                snprintf(vj, sizeof(vj), "%d", registers[baseReg].value);
            else
            {
                // Nome correto da estação que ocupa o registrador
                int idx = 1;
                for (int j = 0; j < registers[baseReg].busyBy; j++)
                    if (stations[j].type == stations[registers[baseReg].busyBy].type)
                        idx++;
                snprintf(qj, sizeof(qj), "%s%d",
                         (stations[registers[baseReg].busyBy].type == Load) ? "Load" : (stations[registers[baseReg].busyBy].type == Store)    ? "Store"
                                                                                   : (stations[registers[baseReg].busyBy].type == Adder)      ? "Add"
                                                                                   : (stations[registers[baseReg].busyBy].type == Multiplier) ? "Mult"
                                                                                                                                              : "RS",
                         idx);
            }

            snprintf(A, sizeof(A), "%d + Regs[R%d]", offset, baseReg);
        }
        else
        {
            int rj = inst->threeReg.srcReg1;
            int rk = inst->threeReg.srcReg2;

            if (isRegisterFree(registers[rj], i))
                snprintf(vj, sizeof(vj), "%d", registers[rj].value);
            else
            {
                int idx = 1;
                for (int j = 0; j < registers[rj].busyBy; j++)
                    if (stations[j].type == stations[registers[rj].busyBy].type)
                        idx++;
                snprintf(qj, sizeof(qj), "%s%d",
                         (stations[registers[rj].busyBy].type == Load) ? "Load" : (stations[registers[rj].busyBy].type == Store)    ? "Store"
                                                                              : (stations[registers[rj].busyBy].type == Adder)      ? "Add"
                                                                              : (stations[registers[rj].busyBy].type == Multiplier) ? "Mult"
                                                                                                                                    : "RS",
                         idx);
            }

            if (isRegisterFree(registers[rk], i))
                snprintf(vk, sizeof(vk), "%d", registers[rk].value);
            else
            {
                int idx = 1;
                for (int j = 0; j < registers[rk].busyBy; j++)
                    if (stations[j].type == stations[registers[rk].busyBy].type)
                        idx++;
                snprintf(qk, sizeof(qk), "%s%d",
                         (stations[registers[rk].busyBy].type == Load) ? "Load" : (stations[registers[rk].busyBy].type == Store)    ? "Store"
                                                                              : (stations[registers[rk].busyBy].type == Adder)      ? "Add"
                                                                              : (stations[registers[rk].busyBy].type == Multiplier) ? "Mult"
                                                                                                                                    : "RS",
                         idx);
            }
        }

        // Print para terminal
        printf("| %-6s | %-4s | %-4s | %-4s | %-4s | %-4s | %-4s | %-20s |\n",
               name, "Yes", op,
               (*vj ? vj : "-"),
               (*vk ? vk : "-"),
               (*qj ? qj : "-"),
               (*qk ? qk : "-"),
               (*A ? A : "-"));

        // Print para arquivo
        fprintf(file, "| %s | Yes | %s | %s | %s | %s | %s | %s |\n",
                name, op,
                (*vj ? vj : "-"),
                (*vk ? vk : "-"),
                (*qj ? qj : "-"),
                (*qk ? qk : "-"),
                (*A ? A : "-"));
    }

    fclose(file);
}
