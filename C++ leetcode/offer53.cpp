/*****************************************************************************************************
 *              ��ָoffer��53��
 * ��ʵ��һ����������ƥ�����'.'��'*'��������ʽ��ģʽ�е��ַ�'.'��ʾ����һ���ַ�����'*'��ʾ��ǰ����ַ�
   ���Գ�������Σ�����0�Σ��� �ڱ����У�ƥ����ָ�ַ����������ַ�ƥ������ģʽ�����磬�ַ���"aaa"��ģʽ
   "a.a"��"ab*ac*a"ƥ�䣬������"aa.a"��"ab*a"����ƥ��
 *
 * Input:  �ַ�����ƥ���ַ���
 * Output: true or false
 *
 * Note:���ó��������⣬��main�������βδ��������⣬����match����û�����⣩
���ӣ�https://www.nowcoder.com/questionTerminal/45327ae22b7b413ea21df13ee7d6429c
��Դ��ţ����

	��������Ҫ��������ϸ�о���������������˺ö�β����׵ġ�
	���ȣ��������������
		 1>�����ַ�����Ϊ�գ�����true
		 2>����һ���ַ������գ����ڶ����ַ������ˣ�����false����Ϊ���������޷�
			ƥ��ɹ���,�������һ���ַ������ˣ��ڶ����ַ����ǿգ����ǿ���ƥ���
			���ģ�����ڶ����ַ����ǡ�a*a*a*a*��,���ڡ�*��֮ǰ��Ԫ�ؿ��Գ���0�Σ�
			�����п���ƥ��ɹ���
	֮��Ϳ�ʼƥ���һ���ַ������������ֿ��ܣ�ƥ��ɹ���ƥ��ʧ�ܡ������ǵ�pattern
	��һ���ַ������ǡ�*���� �������Ƿ�����������ۣ�pattern��һ���ַ�Ϊ��*����
	��Ϊ��*����
		  1>pattern��һ���ַ���Ϊ��*������������Ƚϼ򵥣�ֱ��ƥ�䵱ǰ�ַ������
			ƥ��ɹ�������ƥ����һ�������ƥ��ʧ�ܣ�ֱ�ӷ���false��ע�������
			��ƥ��ɹ��������������ַ���ͬ������⣬����һ�����������pattern��
			��ǰ�ַ�Ϊ��.��,ͬʱstr�ĵ�ǰ�ַ���Ϊ��\0����
		  2>pattern��һ���ַ�Ϊ��*��ʱ����΢����һЩ����Ϊ��*�����Դ���0��������
			�������Щ��������ǵ���
			   a>����*��ƥ��0���ַ�ʱ��str��ǰ�ַ����䣬pattern��ǰ�ַ�������λ��
				���������*�����ţ�
			   b>����*��ƥ��1������ʱ��str��ǰ�ַ�������һ����pattern��ǰ�ַ�
				���䡣������ƥ��1���������Կ���һ���������Ϊ����ƥ��һ��ʱ��
				����str�Ƶ�����һ���ַ�����pattern�ַ����䣬�ͻص����ϱߵ����a��
				��ƥ�����һ���ַ�ʱ���൱�ڴ�str����һ���ַ�������ʼƥ�䣩
	֮����д����ͺܼ��ˡ�

 * author: lcxanhui@163.com
 * time: 2019.6.26
 ******************************************************************************************************/
#include<iostream>
#include<string>
#include <stdio.h>
using namespace std;

bool match(char *str, char *pattern)
{
	if (str == NULL || pattern == NULL)
		return false;
	if (*str == '\0'&&*pattern == '\0')  //str��patternͬʱ��ͷ�ˡ�
		return true;
	if (*str != '\0'&&*pattern == '\0')   //strû��ͷ����pattern��ͷ�ˡ�
		return false;
	//������������pattern��һλָ��Ĳ��ǡ�*��
	if (*(pattern + 1) != '*')
	{
		if (*str == *pattern || (*str != '\0'&&*pattern == '.'))
			return match(str + 1, pattern + 1);
		else
			return false;
	}
	//��Ը��ӵ��������pattern��һλָ����ǡ�*��
	else
	{
		if (*str == *pattern || (*str != '\0'&&*pattern == '.'))
			//���ַ�ƥ�����ˣ�����'.'���Ժ������ַ�ƥ�䡣�����ֲ��ԣ�
			return match(str, pattern + 2)           //str���ߣ�pattern��ǰ�����������Ӧ��a* = �����
			       || match(str + 1, pattern + 2)           //str��ǰ��һ����pattern��ǰ�����������Ӧ��a* = a�����
			       || match(str + 1, pattern);              //str��ǰ��һ����pattern���ߣ����Ӧ��a* = aaaa...a�����
		else
			return match(str, pattern + 2);   //���ַ�û��ƥ���ϣ�ֱ������pattern��ǰ�����ַ���
	}
}

void Test(char* testName, char* string, char* pattern, bool expected)
{
	if (testName != NULL)
		printf("%s begins: ", testName);

	if (match(string, pattern) == expected)
		printf("Passed.\n");
	else
		printf("FAILED.\n");
}

int main(int argc, char* argv[])
{
	Test("Test01", "", "", true);
	Test("Test02", "", ".*", true);
	Test("Test03", "", ".", false);
	Test("Test04", "", "c*", true);
	Test("Test05", "a", ".*", true);
	Test("Test06", "a", "a.", false);
	Test("Test07", "a", "", false);
	Test("Test08", "a", ".", true);
	Test("Test09", "a", "ab*", true);
	Test("Test10", "a", "ab*a", false);
	Test("Test11", "aa", "aa", true);
	Test("Test12", "aa", "a*", true);
	Test("Test13", "aa", ".*", true);
	Test("Test14", "aa", ".", false);
	Test("Test15", "ab", ".*", true);
	Test("Test16", "ab", ".*", true);
	Test("Test17", "aaa", "aa*", true);
	Test("Test18", "aaa", "aa.a", false);
	Test("Test19", "aaa", "a.a", true);
	Test("Test20", "aaa", ".a", false);
	Test("Test21", "aaa", "a*a", true);
	Test("Test22", "aaa", "ab*a", false);
	Test("Test23", "aaa", "ab*ac*a", true);
	Test("Test24", "aaa", "ab*a*c*a", true);
	Test("Test25", "aaa", ".*", true);
	Test("Test26", "aab", "c*a*b", true);
	Test("Test27", "aaca", "ab*a*c*a", true);
	Test("Test28", "aaba", "ab*a*c*a", false);
	Test("Test29", "bbbba", ".*a*a", true);
	Test("Test30", "bcbbabab", ".*a*a", false);

	return 0;
}