#include <gtest/gtest.h>
#include <string>
#include <sstream>
#include "calculator.h"

TEST(CalculatorTesting, testNumber)
{
    std::string str = "5";
    double res = Calculator::calculate(str);
    ASSERT_DOUBLE_EQ(5, res);
}
TEST(CalculatorTesting, testNumber1)
{
    std::string str = "-5";
    double res = Calculator::calculate(str);
    ASSERT_DOUBLE_EQ(-5, res);
}
TEST(CalculatorTesting, testNumber2)
{
    std::string str = " 5 ";
    double res = Calculator::calculate(str);
    ASSERT_DOUBLE_EQ(5, res);
}
TEST(CalculatorTesting, testNumber3)
{
    std::string str = "\t 5 \t";
    double res = Calculator::calculate(str);
    ASSERT_DOUBLE_EQ(5, res);
}
TEST(CalculatorTesting, testNumber4)
{
    std::string str = "65.96";
    double res = Calculator::calculate(str);
    ASSERT_DOUBLE_EQ(65.96, res);
}
TEST(CalculatorTesting, testNumber5)
{
    std::string str = "65,96";
    double res = Calculator::calculate(str);
    ASSERT_DOUBLE_EQ(65.96, res);
}
TEST(CalculatorTesting, testNumber6)
{
    std::string str = "10000000";
    double res = Calculator::calculate(str);
    ASSERT_DOUBLE_EQ(10000000.0, res);
}
TEST(CalculatorTesting, testNumber7)
{
    std::string str = "-10000000";
    double res = Calculator::calculate(str);
    ASSERT_DOUBLE_EQ(-10000000.0, res);
}


TEST(CalculatorTesting, testExceptionAfterUnknownMinus)
{
    std::string str = "-+45";
    ASSERT_THROW(Calculator::calculate(str), std::string);

}

TEST(CalculatorTesting, testExceptionUnknownSymbol)
{
    std::string str = "abc";
    ASSERT_THROW(Calculator::calculate(str), std::string);

}


TEST(CalculatorTesting, testSum)
{
    std::string str = "5 + 2";
    double res = Calculator::calculate(str);
    ASSERT_DOUBLE_EQ(7, res);
}
TEST(CalculatorTesting, testSum2)
{
    std::string str = "-5 + 2";
    double res = Calculator::calculate(str);
    ASSERT_DOUBLE_EQ(-3, res);
}
TEST(CalculatorTesting, testSum3)
{
    std::string str = "\t-5 \t+ 2 \t";
    double res = Calculator::calculate(str);
    ASSERT_DOUBLE_EQ(-3, res);
}

TEST(CalculatorTesting, testSub)
{
    std::string str = "5 - 2";
    double res = Calculator::calculate(str);
    ASSERT_DOUBLE_EQ(3, res);
}

TEST(CalculatorTesting, testSub1)
{
    std::string str = "100500 - 200500";
    double res = Calculator::calculate(str);
    ASSERT_DOUBLE_EQ(-100000, res);
}


TEST(CalculatorTesting, testMultiplying)
{
    std::string str = "8*8";
    double res = Calculator::calculate(str);
    ASSERT_DOUBLE_EQ(64, res);
}

TEST(CalculatorTesting, testMultiplying1)
{
    std::string str = "86.5*85,2";
    double res = Calculator::calculate(str);
    ASSERT_DOUBLE_EQ(7369.8, res);
}

TEST(CalculatorTesting, testMultiplying2)
{
    std::string str = "86.5*(-85,2)";
    double res = Calculator::calculate(str);
    ASSERT_DOUBLE_EQ(-7369.8, res);
}

TEST(CalculatorTesting, testDiv)
{
    std::string str = "86.5/85,2";
    double res = Calculator::calculate(str);
    ASSERT_DOUBLE_EQ(1.0152582159624413, res);
}
TEST(CalculatorTesting, testDiv1)
{
    std::string str = "-5/0.1";
    double res = Calculator::calculate(str);
    ASSERT_DOUBLE_EQ(-50, res);
}

TEST(CalculatorTesting, testManyOperators)
{
    std::string str = "-1 + 5 - 3";
    double res = Calculator::calculate(str);
    ASSERT_DOUBLE_EQ(1, res);
}
TEST(CalculatorTesting, testManyOperators1)
{
    std::string str = "-10 + (8*2,5)-(3/1,5)";
    double res = Calculator::calculate(str);
    ASSERT_DOUBLE_EQ(8, res);
}

TEST(CalculatorTesting, testManyOperators2)
{
    std::string str = "1 + (2* (2.5 + 2.5 + (3-2) )) - (3/ 1,5)";
    double res = Calculator::calculate(str);
    ASSERT_DOUBLE_EQ(11, res);
}

TEST(CalculatorTesting, testExceptionUnknownSymbol3)
{
    std::string str = "1.1 + 2.1 + abc";
    ASSERT_THROW(Calculator::calculate(str), std::string);

}



int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
