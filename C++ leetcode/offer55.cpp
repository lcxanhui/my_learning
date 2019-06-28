/*****************************************************************************************************
 *                      剑指offer第55题
 * 请实现一个函数用来找出字符流中第一个只出现一次的字符。例如，当从字符流中只读出前两个字符"go"时，
   第一个只出现一次的字符是"g"。当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。
 *
 * Input:  字符流
 * Output: 字符流中的第一个不重复的数字
 *
 * Note:（该程序有问题，测试不能通过）
	由于在字符流中，字符只能一个接着一个的从字符串中出来，因此需要定义一个数据容器来保存字符串在字符流中
	的位置，而hash表可以充当该角色，并且由于每个字符占用8字节空间，因此可以用256大小的hash表进行保存，并且
	统计每个字符在hash表中的数目，返回第一个只出现一次的字符。

 * author: lcxanhui@163.com
 * time: 2019.6.28
 ******************************************************************************************************/

#include<iostream>
#include<string>
#include<functional> 
#include<limits>
using namespace std;

class Solution {
public:
	void Insert(char ch)
	{
		s += ch;  //此数据流中如果出现ch字符，则将ch字符放入s中的某个位置
		hash[ch]++;  
	}
	char firstAppearOnes() {
		for (int i = 0; i < s.size(); i++)
		{
			if (hash[s[i] == 1])   //如果hash表的某个位置为1，则返回该数，否则返回“#”
				return s[i];
		}
		return '#';
	}
private:
	// 将数据封装，面向对象实现对数据的封装性
	string s;
	char hash[256] = { 0 };   // 由于char占用1个字节，因此可以用256个大小的hash表进行初始化
};

void Test(const char* testName, Solution chars, char expected)
{
	if (testName != NULL)
		printf("%s begins: ", testName);

	if (chars.firstAppearOnes() == expected)
		printf("Passed.\n");
	else
		printf("FAILED.\n");
}

int main(int argc, char* argv[])
{
	Solution chars;

	Test("Test1", chars, '\0');

	chars.Insert('g');
	Test("Test2", chars, 'g');

	chars.Insert('o');
	Test("Test3", chars, 'g');

	chars.Insert('o');
	Test("Test4", chars, 'g');

	chars.Insert('g');
	Test("Test5", chars, '\0');

	chars.Insert('l');
	Test("Test6", chars, 'l');

	chars.Insert('e');
	Test("Test7", chars, 'l');

	return 0;
}