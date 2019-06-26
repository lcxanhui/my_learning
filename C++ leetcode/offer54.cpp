/*****************************************************************************************************
 *                      剑指offer第54题
 * 请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，字符串"+100","5e2","-123","3.1416"
   和"-1E-16"都表示数值。 但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。
 *
 * Input:  字符串
 * Output: true or false
 *
 * Note:（该程序有问题，最后的三个测试不能通过）
    具体解析看代码，情况比较繁琐，但是总体不难

 * author: lcxanhui@163.com
 * time: 2019.6.26
 ******************************************************************************************************/
#include<iostream>
#include<string>
using namespace std;

bool isNumeric(const char *str)
{
	if (str == NULL)
		return false;
	// 标记符号、小数点、e是否出现过
	bool sign = false, decimal = false, hasE = false;
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == 'e' || str[i] == 'E')
		{
			// e后面一定要接数字，即不是最后一位
			if (i == strlen(str) - 1)
				return false;
			// 不能同时存在两个e
			if (hasE==true)
				return false;
			hasE = true;
		}
		else if (str[i] == '+' || str[i] == '-')
		{
			// 第二次出现+-符号，则必须紧接在e或者E之后
			if (sign==true && str[i - 1] != 'e' && str[i - 1] != 'E')
				return false;
			// 第一次出现+-符号，且不是在字符串开头，则也必须紧接在e之后
			if (sign==false && i > 0 && str[i - 1] != 'e' && str[i - 1] != 'E')
				return false;
			sign = true;
		}
		else if (str[i] == '.')
		{
			// e后面不能接小数点，小数点不能出现两次
			if (decimal || hasE)
				return false;
			decimal = true;
		}
		else if (str[i]<'0' || str[i]>'9')     // 其他不合法字符
			return false;
	}
	return true;
}

void Test(const char* testName, const char* str, bool expected)
{
	if (testName != NULL)
		printf("%s begins: ", testName);

	if (isNumeric(str) == expected)
		printf("Passed.\n");
	else
		printf("FAILED.\n");
}


int main(int argc, char* argv[])
{
	Test("Test1", "100", true);
	Test("Test2", "123.45e+6", true);
	Test("Test3", "+500", true);
	Test("Test4", "5e2", true);
	Test("Test5", "3.1416", true);
	Test("Test6", "600.", true);
	Test("Test7", "-.123", true);
	Test("Test8", "-1E-16", true);
	Test("Test9", "1.79769313486232E+308", true);

	printf("\n\n");

	Test("Test10", "12e", false);
	Test("Test11", "1a3.14", false);
	Test("Test12", "1+23", false);
	Test("Test13", "1.2.3", false);
	Test("Test14", "+-5", false);
	Test("Test15", "12e+5.4", false);
	Test("Test16", ".", false);
	Test("Test17", ".e1", false);
	Test("Test18", "+.", false);

	return 0;
}