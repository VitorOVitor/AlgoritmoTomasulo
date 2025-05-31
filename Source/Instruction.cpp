#include "Instruction.hpp"
#include <sstream>
#include <iostream>

const int LOAD_STORE_CTIME = 2;
const int ADD_SUB_CTIME = 3;
const int MULT_DIV_CTIME = 8;

Instruction::Instruction() 
    : operation(Operation::ADD), type(InstructionType::ThreeReg),
      targetReg(0), srcReg1(0), srcReg2_or_offset(0),
      issuedAt(-1), startedAt(-1), finishedAt(-1), writtenAt(-1) {}

Instruction::Instruction(Operation op, int target, int src1, int src2_or_offset, InstructionType type) 
    : operation(op), type(type), targetReg(target), 
      srcReg1(src1), srcReg2_or_offset(src2_or_offset),
      issuedAt(-1), startedAt(-1), finishedAt(-1), writtenAt(-1) {}

Operation Instruction::getOperation() const { return operation; }
InstructionType Instruction::getType() const { return type; }
int Instruction::getTargetReg() const { return targetReg; }
int Instruction::getSrcReg1() const { return srcReg1; }

int Instruction::getSrcReg2() const { 
    if(type != InstructionType::ThreeReg) 
        throw std::logic_error("Instruction is not ThreeReg type");
    return srcReg2_or_offset; 
}

int Instruction::getOffset() const { 
    if(type != InstructionType::TwoReg) 
        throw std::logic_error("Instruction is not TwoReg type");
    return srcReg2_or_offset; 
}

int Instruction::getIssuedAt() const { return issuedAt; }
int Instruction::getStartedAt() const { return startedAt; }
int Instruction::getFinishedAt() const { return finishedAt; }
int Instruction::getWrittenAt() const { return writtenAt; }

void Instruction::setIssuedAt(int cycle) { issuedAt = cycle; }
void Instruction::setStartedAt(int cycle) { startedAt = cycle; }
void Instruction::setFinishedAt(int cycle) { finishedAt = cycle; }
void Instruction::setWrittenAt(int cycle) { writtenAt = cycle; }

std::string Instruction::getOperationName() const {
    switch(operation) {
        case Operation::LW: return "LW";
        case Operation::SW: return "SW";
        case Operation::ADD: return "ADD";
        case Operation::SUB: return "SUB";
        case Operation::MUL: return "MUL";
        case Operation::DIV: return "DIV";
        default: return "UNKNOWN";
    }
}

int Instruction::getOperationTime() const {
    switch(operation) {
        case Operation::LW:
        case Operation::SW:
            return LOAD_STORE_CTIME;
        case Operation::ADD:
        case Operation::SUB:
            return ADD_SUB_CTIME;
        case Operation::MUL:
        case Operation::DIV:
            return MULT_DIV_CTIME;
        default:
            return -1;
    }
}

std::vector<int> Instruction::getAssociatedRegisters() const {
    std::vector<int> registers;
    registers.push_back(targetReg);
    registers.push_back(srcReg1);
    
    if(type == InstructionType::ThreeReg) {
        registers.push_back(srcReg2_or_offset);
    } else {
        registers.push_back(-1);
    }
    
    return registers;
}

void Instruction::debugPrint() const {
    std::cout << "\n[Operation]: '" << getOperationName() << "' - ";
    if(type == InstructionType::TwoReg) {
        std::cout << "(TwoReg)\n";
        std::cout << "[target]: " << targetReg << "\n";
        std::cout << "[source]: " << srcReg1 << "\n";
        std::cout << "[offset]: " << srcReg2_or_offset << "\n";
    } else {
        std::cout << "(ThreeReg)\n";
        std::cout << "[target]: " << targetReg << "\n";
        std::cout << "[source_1]: " << srcReg1 << "\n";
        std::cout << "[source_2]: " << srcReg2_or_offset << "\n";
    }
    std::cout << "[issuedAt]: " << issuedAt << "\n";
    std::cout << "[startedAt]: " << startedAt << "\n";
    std::cout << "[finishedAt]: " << finishedAt << "\n";
    std::cout << "[writtenAt]: " << writtenAt << "\n";
}

void Instruction::trim(std::string& str) {
    str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](int ch) {
        return !std::isspace(ch);
    }));
    str.erase(std::find_if(str.rbegin(), str.rend(), [](int ch) {
        return !std::isspace(ch);
    }).base(), str.end());
}

void Instruction::remove_newline(std::string& str) {
    str.erase(std::remove(str.begin(), str.end(), '\n'), str.end());
    str.erase(std::remove(str.begin(), str.end(), '\r'), str.end());
}

void Instruction::panicParserError(const std::string& message, const std::string& instruction) {
    std::cerr << "\033[1;31m[ParserError]\033[0m at '\033[0;36m" 
              << instruction << "\033[0m " << message << "\n";
    throw std::runtime_error("Parser error: " + message);
}

Operation Instruction::parseOperation(const std::string& opStr) {
    std::string upper = opStr;
    std::transform(upper.begin(), upper.end(), upper.begin(), ::toupper);
    
    if(upper == "SW") return Operation::SW;
    if(upper == "LW") return Operation::LW;
    if(upper == "ADD") return Operation::ADD;
    if(upper == "SUB") return Operation::SUB;
    if(upper == "MUL") return Operation::MUL;
    if(upper == "DIV") return Operation::DIV;

    panicParserError("Invalid operation: " + opStr, opStr);
    return Operation::ADD;
}

InstructionType Instruction::getInstructionType(Operation op) {
    switch(op) {
        case Operation::ADD:
        case Operation::SUB:
        case Operation::MUL:
        case Operation::DIV:
            return InstructionType::ThreeReg;
        default:
            return InstructionType::TwoReg;
    }
}

void Instruction::parseTwoReg(const std::string& instructionStr, int& target, int& src, int& offset) {
    std::istringstream iss(instructionStr);
    char discard;
    
    if (!(iss >> discard) || discard != 'R') 
        panicParserError("Expected 'R' at start", instructionStr);
    
    if (!(iss >> target)) 
        panicParserError("Expected target register number", instructionStr);
    
    if (!(iss >> discard) || discard != ',') 
        panicParserError("Expected comma after target register", instructionStr);
    
    if (!(iss >> offset)) 
        panicParserError("Expected offset value", instructionStr);
    
    if (!(iss >> discard) || discard != '(') 
        panicParserError("Expected '(' before source register", instructionStr);
    
    if (!(iss >> discard) || discard != 'R') 
        panicParserError("Expected 'R' before source register", instructionStr);
    
    if (!(iss >> src)) 
        panicParserError("Expected source register number", instructionStr);
    
    if (!(iss >> discard) || discard != ')') 
        panicParserError("Expected ')' after source register", instructionStr);
}

void Instruction::parseThreeReg(const std::string& instructionStr, int& target, int& src1, int& src2) {
    std::istringstream iss(instructionStr);
    char discard;
    
    if (!(iss >> discard) || discard != 'R') 
        panicParserError("Expected 'R' at start", instructionStr);
    
    if (!(iss >> target)) 
        panicParserError("Expected target register number", instructionStr);
    
    if (!(iss >> discard) || discard != ',') 
        panicParserError("Expected comma after target register", instructionStr);
    
    if (!(iss >> discard) || discard != 'R') 
        panicParserError("Expected 'R' before first source register", instructionStr);
    
    if (!(iss >> src1)) 
        panicParserError("Expected first source register number", instructionStr);
    
    if (!(iss >> discard) || discard != ',') 
        panicParserError("Expected comma after first source register", instructionStr);
    
    if (!(iss >> discard) || discard != 'R') 
        panicParserError("Expected 'R' before second source register", instructionStr);
    
    if (!(iss >> src2)) 
        panicParserError("Expected second source register number", instructionStr);
}

Instruction Instruction::parseInstruction(const std::string& instructionStr) {
    std::string trimmed = instructionStr;
    remove_newline(trimmed);
    trim(trimmed);
    
    size_t spacePos = trimmed.find(' ');
    if (spacePos == std::string::npos) 
        panicParserError("Invalid instruction format (no space)", instructionStr);
    
    std::string opStr = trimmed.substr(0, spacePos);
    std::string argsStr = trimmed.substr(spacePos + 1);
    trim(argsStr);
    
    Operation op = parseOperation(opStr);
    InstructionType type = getInstructionType(op);
    
    int target, src1, src2_or_offset;
    
    if (type == InstructionType::TwoReg) {
        parseTwoReg(argsStr, target, src1, src2_or_offset);
    } else {
        parseThreeReg(argsStr, target, src1, src2_or_offset);
    }
    
    return Instruction(op, target, src1, src2_or_offset, type);
}