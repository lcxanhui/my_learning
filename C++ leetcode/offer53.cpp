/*****************************************************************************************************
 *              剑指offer第53题
 * 请实现一个函数用来匹配包括'.'和'*'的正则表达式。模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符
   可以出现任意次（包含0次）。 在本题中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式
   "a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配
 *
 * Input:  字符串和匹配字符串
 * Output: true or false
 *
 * Note:（该程序有问题，在main函数中形参传递有问题，但是match函数没有问题）
链接：https://www.nowcoder.com/questionTerminal/45327ae22b7b413ea21df13ee7d6429c
来源：牛客网

	解这题需要把题意仔细研究清楚，反正我试了好多次才明白的。
	首先，考虑特殊情况：
		 1>两个字符串都为空，返回true
		 2>当第一个字符串不空，而第二个字符串空了，返回false（因为这样，就无法
			匹配成功了,而如果第一个字符串空了，第二个字符串非空，还是可能匹配成
			功的，比如第二个字符串是“a*a*a*a*”,由于‘*’之前的元素可以出现0次，
			所以有可能匹配成功）
	之后就开始匹配第一个字符，这里有两种可能：匹配成功或匹配失败。但考虑到pattern
	下一个字符可能是‘*’， 这里我们分两种情况讨论：pattern下一个字符为‘*’或
	不为‘*’：
		  1>pattern下一个字符不为‘*’：这种情况比较简单，直接匹配当前字符。如果
			匹配成功，继续匹配下一个；如果匹配失败，直接返回false。注意这里的
			“匹配成功”，除了两个字符相同的情况外，还有一种情况，就是pattern的
			当前字符为‘.’,同时str的当前字符不为‘\0’。
		  2>pattern下一个字符为‘*’时，稍微复杂一些，因为‘*’可以代表0个或多个。
			这里把这些情况都考虑到：
			   a>当‘*’匹配0个字符时，str当前字符不变，pattern当前字符后移两位，
				跳过这个‘*’符号；
			   b>当‘*’匹配1个或多个时，str当前字符移向下一个，pattern当前字符
				不变。（这里匹配1个或多个可以看成一种情况，因为：当匹配一个时，
				由于str移到了下一个字符，而pattern字符不变，就回到了上边的情况a；
				当匹配多于一个字符时，相当于从str的下一个字符继续开始匹配）
	之后再写代码就很简单了。

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
	if (*str == '\0'&&*pattern == '\0')  //str和pattern同时到头了。
		return true;
	if (*str != '\0'&&*pattern == '\0')   //str没到头但是pattern到头了。
		return false;
	//最简答的情况，当pattern下一位指向的不是“*”
	if (*(pattern + 1) != '*')
	{
		if (*str == *pattern || (*str != '\0'&&*pattern == '.'))
			return match(str + 1, pattern + 1);
		else
			return false;
	}
	//相对复杂的情况，当pattern下一位指向的是“*”
	else
	{
		if (*str == *pattern || (*str != '\0'&&*pattern == '.'))
			//首字符匹配上了，其中'.'可以和任意字符匹配。有三种策略：
			return match(str, pattern + 2)           //str不走，pattern往前走两步：这对应着a* = 的情况
			       || match(str + 1, pattern + 2)           //str往前走一步，pattern往前走两步：这对应着a* = a的情况
			       || match(str + 1, pattern);              //str往前走一步，pattern不走：这对应着a* = aaaa...a的情况
		else
			return match(str, pattern + 2);   //首字符没有匹配上，直接跳过pattern的前两个字符。
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