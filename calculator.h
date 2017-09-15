#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <string>
#include <vector>

class istream;
namespace Calculator
{
    enum Operators{ADD = '+', SUB = '-', MUL = '*', DIV = '/'};
    bool validateParentheses(const std::string &str);
    std::vector<std::string> translateToReversePolish(const std::string &str);
    double calculate(std::string str);
};

#endif // CALCULATOR_H
