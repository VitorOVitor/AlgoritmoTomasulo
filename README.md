# Tomasulo Simulator

Este projeto implementa um simulador do algoritmo de Tomasulo, utilizado para execução dinâmica de instruções em processadores, permitindo reordenação e paralelismo de instruções.

## Como usar

Compile (se necessário) e execute o programa com:

```bash
./tomasulo.exe <INPUT_FILE> <OUTPUT_FILE>
```

- `<INPUT_FILE>`: arquivo de entrada com as instruções.
- `<OUTPUT_FILE>`: arquivo de saída onde os logs serão salvos em formato Markdown.

## Exemplo de Saída

```md
# CICLE X
## Log
* [2] Dispatched
* [1] Started

## Registers
[
{"id": 1, "busyByStation": 0, "busyByInst": 1, "v": 1},
]
## Stations
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 1,
        "startedAt": 2,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "ADDER (1)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 2,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```

## Arquitetura

- 32 registradores (`R0` a `R31`), cada um inicia com seu índice como valor.
- Estações de reserva configuráveis (padrão: 2 Adders, 1 Multiplier, 2 Load, 2 Store).
- Ciclos para cada operação (padrão):
  - Load/Store: 2 ciclos
  - Add/Sub: 3 ciclos
  - Mult/Div: 8 ciclos

## Funcionamento

1. Lê e interpreta as instruções do arquivo de entrada.
2. Inicializa registradores e estações de reserva.
3. Em cada ciclo:
   - Despacha instruções para as estações disponíveis.
   - Atualiza o estado das instruções em execução.
   - Gerencia dependências entre registradores e instruções.

## Instruções Suportadas

```assembly
SW Rx,y(Rz)
LW Rx,y(Rz)
SUB Rx,Ry,Rz
DIV Rx,Ry,Rz
MUL Rx,Ry,Rz
ADD Rx,Ry,Rz
```

## Personalização

- Para alterar a quantidade de registradores, modifique `REG_AMOUNT` em `main.c` e `Log.h`.
- Para alterar as estações de reserva, ajuste a variável `reservationStations` em `main.c` e `STATIONS_AMOUNT` nos arquivos relevantes.

---

Obrigado por ler :D
