/*****************************************************************************************************
 *         剑指offer第35题
 * 在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置, 
   如果没有则返回 -1（需要区分大小写）.
 *
 * Input:  string s
 * Output: 只出现一次字符位置
 *
 * Note: （利用hashmap）
 * 定义hashmap的键值是字符，而值是该字符出现的次数（具体见leetcode381题）
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
	map<char, int> m;  //建立hashmap
	for (int i = 0; i < s.size(); i++)
	{
		if (m.count(s[i]) != 0)   //如果该键值的计数不等于0，则将值＋1
			m[s[i]]++;
		else
			m[s[i]] = 1;
	}
	for (int i = 0; i < s.size(); i++)
	{
		if (m[s[i]] == 1)   //记录第一个键值的出现的位置
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