#ifndef INSTRUCTION_HPP
#define INSTRUCTION_HPP

#include <string>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <cctype>

enum class Operation { LW, SW, ADD, SUB, MUL, DIV };
enum class InstructionType { TwoReg, ThreeReg };

class Instruction {
public:
    Instruction();
    Instruction(Operation op, int target, int src1, int src2_or_offset, InstructionType type);
    
    static Operation parseOperation(const std::string& opStr);
    static InstructionType getInstructionType(Operation op);
    static Instruction parseInstruction(const std::string& instructionStr);
    
    Operation getOperation() const;
    InstructionType getType() const;
    int getTargetReg() const;
    int getSrcReg1() const;
    int getSrcReg2() const;
    int getOffset() const;
    int getIssuedAt() const;
    int getStartedAt() const;
    int getFinishedAt() const;
    int getWrittenAt() const;
    
    void setIssuedAt(int cycle);
    void setStartedAt(int cycle);
    void setFinishedAt(int cycle);
    void setWrittenAt(int cycle);
    
    std::string getOperationName() const;
    int getOperationTime() const;
    std::vector<int> getAssociatedRegisters() const;
    void debugPrint() const;

private:
    static void parseTwoReg(const std::string& instructionStr, int& target, int& src, int& offset);
    static void parseThreeReg(const std::string& instructionStr, int& target, int& src1, int& src2);
    static void panicParserError(const std::string& message, const std::string& instruction);
    static void trim(std::string& str);
    static void remove_newline(std::string& str);

    Operation operation;
    InstructionType type;
    int targetReg;
    int srcReg1;
    int srcReg2_or_offset;
    
    int issuedAt;
    int startedAt;
    int finishedAt;
    int writtenAt;
};

#endif // INSTRUCTION_HPP