/*****************************************************************************************************
 *         ��ָoffer��35��
 * ��һ���ַ���(0<=�ַ�������<=10000��ȫ������ĸ���)���ҵ���һ��ֻ����һ�ε��ַ�,����������λ��, 
   ���û���򷵻� -1����Ҫ���ִ�Сд��.
 *
 * Input:  string s
 * Output: ֻ����һ���ַ�λ��
 *
 * Note: ������hashmap��
 * ����hashmap�ļ�ֵ���ַ�����ֵ�Ǹ��ַ����ֵĴ����������leetcode381�⣩
 * author: lcxanhui@163.com
 * time: 2019.5.16
 ******************************************************************************************************/
#include<iostream>
#include<string>
#include<algorithm>
#include<map>
using namespace std;

int FirstNotRepeatingChar(string s)
{
	map<char, int> m;  //����hashmap
	for (int i = 0; i < s.size(); i++)
	{
		if (m.count(s[i]) != 0)   //����ü�ֵ�ļ���������0����ֵ��1
			m[s[i]]++;
		else
			m[s[i]] = 1;
	}
	for (int i = 0; i < s.size(); i++)
	{
		if (m[s[i]] == 1)   //��¼��һ����ֵ�ĳ��ֵ�λ��
			return i;
	}
	return -1;
}

int main(void)
{
	string s="leetcodelove";
	int result;
	result = FirstNotRepeatingChar(s);
	cout << result;
	return 0;
}