/*****************************************************************************************************
 *         剑指offer第42-2题
 * 题目描述
 * 用字符串模拟这个指令的运算结果。对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。例如，
   字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”
 *
 * Input:  字符串和翻转的位置
 * Output: 翻转后的字符串
 *
 * Note: （着重掌握翻转字符串的操作，是各种字符串操作的基石）
 *  首先将前N个字符串进行翻转，再将后len-N+1的字符串进行翻转，最后将所有的字符进行翻转。
    解释数学：YX=（XTYT）T ，其中T为转置
 * author: lcxanhui@163.com
 * time: 2019.5.30
 ******************************************************************************************************/
#include<iostream>
#include<string>
using namespace std;


// 翻转字符串的经典代码，掌握
void Reverse(string& str, int begin, int end)
{
	if (begin < 0 || end < 0)
		return;
	while (begin < end)    // 判断条件
	{
		char temp;
		temp = str[begin];
		str[begin] = str[end];
		str[end] = temp;
		begin++;
		end--;
	}
}

string LeftRotateString(string str,int n)
{
	int len = str.size();
	if (len <= 0 || n<=0)
		return str;
	if (n > len)
		n = n % len;   //如果位置N大于len，比如12>9，则求余运算后为3，在字符串的第3个位置进行翻转
	string& temp = str;
	Reverse(temp, 0, n - 1);
	Reverse(temp, n, len - 1);
	Reverse(temp, 0, len - 1);
	return str;
}

int main()
{
	string str = "I am a student.";
	int n;
	cin >> n;
	string res = LeftRotateString(str, n);
	cout << res;
	return 0;
}