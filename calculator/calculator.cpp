#include "calculator.h"
#include <iostream>
#include <string>
#include <cmath>

using Number = double;

enum class Operation {
    Add,
    Subtract,
    Multiply,
    Devide,
    Power,
    SetNumber,
    Clear,
    Print,
    Memorize,
    Load,
    Quit,
    Unknown
};


bool ReadNumber(Number& result) {
    if (!(std::cin >> result)) {
        std::cerr << "Error: Numeric operand expected" << std::endl;
        return false;
    }
    return true;
}

Operation ReadCommand(std::string& input_cmd) {
    std::cin >> input_cmd;
    if (input_cmd == "+") return Operation::Add;
    if (input_cmd == "-") return Operation::Subtract;
    if (input_cmd == "*") return Operation::Multiply;
    if (input_cmd == "/") return Operation::Devide;
    if (input_cmd == "**") return Operation::Power;
    if (input_cmd == ":") return Operation::SetNumber;
    if (input_cmd == "c") return Operation::Clear;
    if (input_cmd == "=") return Operation::Print;
    if (input_cmd == "s") return Operation::Memorize;
    if (input_cmd == "l") return Operation::Load;
    if (input_cmd == "q") return Operation::Quit;

    return Operation::Unknown;
}



bool RunCalculatorCycle() {
    Number input_number, result, memory;
    bool is_memorized = false;
    std::string input_cmd;
    if (!ReadNumber(input_number)) {
        return false;
    }
    result = input_number;
    while(true) {
        Operation op = ReadCommand(input_cmd);
        switch (op) {
            case Operation::Add:
                if (!ReadNumber(input_number)) {
                    return false;
                }
                result += input_number;
                break;
                
            case Operation::Subtract:
                if (!ReadNumber(input_number)) {
                    return false;
                }
                result -= input_number;
                break;
                
            case Operation::Multiply:
                if (!ReadNumber(input_number)) {
                    return false;
                }
                result *= input_number;
                break;
            case Operation::Devide:
                if (!ReadNumber(input_number)) {
                    return false;
                }
                result /= input_number;
                break;
            case Operation::Power:
                if (!ReadNumber(input_number)) {
                    return false;
                }
                result = std::pow(result, input_number);
                break;
                
            case Operation::SetNumber:
                if (!ReadNumber(input_number)) {
                    return false;
                }
                result = input_number;
                break;
            case Operation::Clear:
                result = 0;
                break;
                
            case Operation::Print:
                std::cout << result << std::endl;
                break;
            case Operation::Memorize:
                is_memorized = true;
                memory = result;
                break;
            case Operation::Load:
                if (!is_memorized) {
                    std::cerr << "Error: Memory is empty" << std::endl;
                    return false;
                }
                result = memory;
                break;
            case Operation::Quit:
                return true;
            case Operation::Unknown:
                std::cerr << "Error: Unknown token " << input_cmd << std::endl;
                return false;
        }
    }
}