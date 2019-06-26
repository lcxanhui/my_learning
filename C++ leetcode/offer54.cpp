/*****************************************************************************************************
 *                      ��ָoffer��54��
 * ��ʵ��һ�����������ж��ַ����Ƿ��ʾ��ֵ������������С���������磬�ַ���"+100","5e2","-123","3.1416"
   ��"-1E-16"����ʾ��ֵ�� ����"12e","1a3.14","1.2.3","+-5"��"12e+4.3"�����ǡ�
 *
 * Input:  �ַ���
 * Output: true or false
 *
 * Note:���ó��������⣬�����������Բ���ͨ����
    ������������룬����ȽϷ������������岻��

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
	// ��Ƿ��š�С���㡢e�Ƿ���ֹ�
	bool sign = false, decimal = false, hasE = false;
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == 'e' || str[i] == 'E')
		{
			// e����һ��Ҫ�����֣����������һλ
			if (i == strlen(str) - 1)
				return false;
			// ����ͬʱ��������e
			if (hasE==true)
				return false;
			hasE = true;
		}
		else if (str[i] == '+' || str[i] == '-')
		{
			// �ڶ��γ���+-���ţ�����������e����E֮��
			if (sign==true && str[i - 1] != 'e' && str[i - 1] != 'E')
				return false;
			// ��һ�γ���+-���ţ��Ҳ������ַ�����ͷ����Ҳ���������e֮��
			if (sign==false && i > 0 && str[i - 1] != 'e' && str[i - 1] != 'E')
				return false;
			sign = true;
		}
		else if (str[i] == '.')
		{
			// e���治�ܽ�С���㣬С���㲻�ܳ�������
			if (decimal || hasE)
				return false;
			decimal = true;
		}
		else if (str[i]<'0' || str[i]>'9')     // �������Ϸ��ַ�
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