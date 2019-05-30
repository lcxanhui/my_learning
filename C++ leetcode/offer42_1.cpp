/*****************************************************************************************************
 *         剑指offer第42-1题
 * 题目描述
 * 最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。同事Cat对Fish写的内容颇
   感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。例如，“student. a am I”。后来才意识到，这家伙
   原来把句子单词的顺序翻转了，正确的句子应该是“I am a student.”。
 *
 * Input:  字符串
 * Output: 翻转后的字符串
 *
 * Note: （着重掌握翻转字符串的操作，是各种字符串操作的基石）
 *  首先将所有的字符进行翻转，再将每个单词进行翻转，依据空格来确定单词的起始和终止位置
 * author: lcxanhui@163.com
 * time: 2019.5.30
 ******************************************************************************************************/
#include<iostream>
#include<string>
using namespace std;


// 翻转字符串的经典代码，掌握
void Reverse(string& str, int begin, int end)
{
	if (begin <0 || end < 0)
		return;
	while(begin < end)    // 判断条件
	{
		char temp;
		temp = str[begin];
		str[begin] = str[end];
		str[end] = temp;
		begin++;
		end--;
	}
}

string ReverseSentence(string str)
{
	if (str.size() <= 1)
		return str;
	int begin = 0, end = 0;
	//先求出字符串的总长度
	while (str[end] != '\0')
		end++;
	//此时end指向\0位，要减1指向前一位
	end--;
	//先将整个字符串进行翻转
	Reverse(str, begin, end);

	//下面对字符串的某个单词进行翻转
	begin = end = 0;

	while (str[begin] != '\0')   // 判断循环条件
	{
		if (str[begin] == ' ')    // 如果begin空格位置时，则将begin和end各加一
		{
			begin++;
			end++;
		}
		else if (str[end] == ' ' || str[end] == '\0')  //如果end遍历到空格或者\0时，则将该单词的前后进行翻转
		{
			Reverse(str, begin, --end);    //注意此处是先对end-1，使其先为空格前一位再进行翻转
			begin = ++end;   //此时该独立的单词已经翻转完毕，然后将begin设为end遍历为空格时候的值，再进行下一步操作
		}
		else
			end++;
	}
	return str;
}

int main()
{
	string str = "I am a student.";
	string res = ReverseSentence(str);
	cout << res;
	return 0;
}