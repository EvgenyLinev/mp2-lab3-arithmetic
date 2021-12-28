// тесты для вычисления арифметических выражений

#include <gtest.h>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <arithmetic.h>

TEST(PolishHelp, loyalty_to_priorities1)
{
	string m = ")";
	string s = ")";
	ASSERT_TRUE(PolishHelp(m,s));
}
TEST(PolishHelp, loyalty_to_priorities2)
{
	string m = ")";
	string s = "(";
	ASSERT_TRUE(PolishHelp(m, s));
}
TEST(PolishHelp, loyalty_to_priorities3)
{
	string m = ")";
	string s = "-";
	ASSERT_TRUE(PolishHelp(m, s));
}
TEST(PolishHelp, loyalty_to_priorities4)
{
	string m = ")";
	string s = "+";
	ASSERT_TRUE(PolishHelp(m, s));
}
TEST(PolishHelp, loyalty_to_priorities5)
{
	string m = ")";
	string s = "*";
	ASSERT_TRUE(PolishHelp(m, s));
}
TEST(PolishHelp, loyalty_to_priorities6)
{
	string m = ")";
	string s = "/";
	ASSERT_TRUE(PolishHelp(m, s));
}
TEST(PolishHelp, loyalty_to_priorities7)
{
	string m = ")";
	string s = "~";
	ASSERT_TRUE(PolishHelp(m, s));
}
TEST(DeleteSpaces, correct_whitespace_removal)
{
	string m = " 1";
	string s = "1";
	EXPECT_EQ(DeleteSpaces(m),s);
}
TEST(exam, correctness_of_the_entered_expression1)
{
	string m = "(1+1)-2/3+4-x0/x2*x3";
	ASSERT_TRUE(!exam(m));
}
TEST(exam, correctness_of_the_entered_expression2)
{
	string m = "(-1+1)-2-/3+4--x0-/x2*x-3";
	ASSERT_TRUE(!exam(m));
}
TEST(exam, correctness_of_the_entered_expression3)
{
	string m = "(1+-1)-2/3+4-x0/x2*x3";
	ASSERT_TRUE(!exam(m));
}
TEST(exam, correctness_of_the_entered_expression4)
{
	string m = "(1.0+7)-(-1+-3)";
	ASSERT_TRUE(!exam(m));
}
TEST(exam, correctness_of_the_entered_expression5)
{
	string m = "(1-1-2)/3+4-5*3+1.22/2.22";
	ASSERT_TRUE(exam(m));
}
TEST(start, correctness_of_line_feed_into_an_array)
{
	string m = "(1-1)";
	vector <string> s = { "(","1","-","1",")" };
	EXPECT_EQ(start(m),s);
}
TEST(Polish, the_correctness_of_the_calculations_of_the_Polish_notation1)
{
	vector <string> m = { "(","1","-","1",")" };
	double s = 0;
	EXPECT_EQ(Polish(m), s);
}
TEST(Polish, the_correctness_of_the_calculations_of_the_Polish_notation2)
{
	vector <string> m = { "(","2","*","1",")" };
	double s = 2;
	EXPECT_EQ(Polish(m), s);
}
TEST(Polish, the_correctness_of_the_calculations_of_the_Polish_notation3)
{
	vector <string> m = { "(","1","/","1",")" };
	double s = 1;
	EXPECT_EQ(Polish(m), s);
}
TEST(Polish, the_correctness_of_the_calculations_of_the_Polish_notation4)
{
	vector <string> m = { "(","4","*","1",")" };
	double s = 4;
	EXPECT_EQ(Polish(m), s);
}

