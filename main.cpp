#include "calculator.h"
#include <iostream>

int main(int argc, char* argv[])
{
    std::string expression = "";
    std::cout.precision(2);
    std::cout << std::fixed;

    std::cout << "Enter expression:" << std::endl;

    std::getline(std::cin, expression);
    while (expression != "exit")
    {
        try{
        std::cout << expression  << " = " << Calculator::calculate(expression) << std::endl;
        }
        catch(const std::string &str)
        {
            std::cout << str << std::endl;
        }
        catch(...)
        {
            std::cout << "ERROR" << std::endl;
        }
        std::getline(std::cin, expression);
    }
}
