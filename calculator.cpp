#include "calculator.h"
#include <iostream>
#include <sstream>
#include <stack>


std::vector<std::string> Calculator::translateToReversePolish(const std::string &str)
{
    std::stringstream strstr(str);
    char ch = 0;
    double res = 0;
    double val = 0;
    std::stack<char> stack;

    std::vector<std::string> ret;
    bool lastSymbolAfterOpeningParentheses = false;

    while (strstr >> ch)
    {

        switch (ch)
        {

        case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': case '.':
            strstr.putback(ch);
            strstr >> val;
            ret.push_back(std::to_string(val));
            lastSymbolAfterOpeningParentheses = false;
            break;

        case SUB:
            if (ret.empty() || (!stack.empty() && stack.top() == '(' && lastSymbolAfterOpeningParentheses )) //если это первый символ, или символ после скобки - то это символ отрицательного числа
            {
                char ch2 = 0;
                strstr >> ch2;
                if (isdigit(ch2))
                {
                    strstr.putback(ch2);
                    strstr.putback(ch);
                    strstr >> val;
                    ret.push_back(std::to_string(val));
                }
                else
                    throw std::string("Error: unknown symbol after\"-\":" + ch2);
            }
            else
            {
                while (!stack.empty() &&( stack.top() == '-' || stack.top() == '+' || stack.top() == '*' || stack.top() == '/'))
                {
                    ret.push_back(std::string(1, stack.top()));
                    stack.pop();
                }
                stack.push(SUB);
                lastSymbolAfterOpeningParentheses = false;
            }
            break;
        case ADD:
            if (!stack.empty())
                while (!stack.empty() && (stack.top() == '-' || stack.top() == '+' || stack.top() == '*' || stack.top() == '/'))
                {
                    ret.push_back(std::string(1, stack.top()));
                    stack.pop();
                }
            stack.push(ADD);
            lastSymbolAfterOpeningParentheses = false;
            break;

        case MUL:
            while (!stack.empty() && (stack.top() == '*' || stack.top() == '/'))
            {
                ret.push_back(std::string(1, stack.top()));
                stack.pop();
            }
            stack.push(MUL);
            lastSymbolAfterOpeningParentheses = false;
            break;

        case DIV:
            while (!stack.empty() && (stack.top() == '*' || stack.top() == '/'))
            {
                ret.push_back(std::string(1, stack.top()));
                stack.pop();
            }
            stack.push(DIV);
            lastSymbolAfterOpeningParentheses = false;
            break;

        case '(':
            stack.push(ch);
            lastSymbolAfterOpeningParentheses = true;
            break;

        case ')':
            while (stack.top() != '(' && !stack.empty())
            {
                ret.push_back(std::string(1, stack.top()));
                stack.pop();
            }
            if (stack.empty())
                throw std::string("Error: wrong parentheses");
            stack.pop();
            lastSymbolAfterOpeningParentheses = false;
            break;



        default:
            std::string str;
            strstr.putback(ch);
            strstr >> str;
            throw std::string("Unknown symbol: " + str);
        }
    }
    while (!stack.empty())
    {
        ret.push_back(std::string(1, stack.top()));
        stack.pop();
    }
    return ret;
}




double Calculator::calculate(std::string str)
{
    if (str.empty())
        throw std::string("Error: Empty string");
    if (!validateParentheses(str))
        throw std::string("Error: wrong parentheses");

    double res = 0;
    std::stack<double> stack;
    double tmpVal = 0;

    int s = str.size();

    size_t n = str.find_first_of(',');
    while (n != std::string::npos)
    {
        str.replace(n, 1, 1, '.');
        n = str.find_first_of(',');
    }


    std::vector<std::string> rp = translateToReversePolish(str);

    for (auto it = rp.begin(); it != rp.end(); it++)
    {
        if (*it=="*" || *it == "/" || *it == "+" || *it == "-")
        {
            double second = 0;
            double first = 0;
            if (!stack.empty())
            {
                second = stack.top();
                stack.pop();
            }
            else throw std::string("Unknown Error");

            if (!stack.empty())
            {
                first = stack.top();
                stack.pop();
            }
            else throw std::string("Unknown Error");

            if (*it == "*")
                stack.push(first*second);
            if (*it == "/")
                stack.push(first/second);
            if (*it == "+")
                stack.push(first+second);
            if (*it == "-")
                stack.push(first-second);
        }
        else
            stack.push(std::stod(*it));



    }

    return stack.top();
}

bool Calculator::validateParentheses(const std::string &str)
{
    std::stack<char> st;
    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] == '(')
            st.push('(');
        if (str[i] == ')')
            if (st.empty())
                return false;
            else
                st.pop();
    }

    return st.empty();
}
