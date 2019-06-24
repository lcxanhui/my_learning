/*****************************************************************************************************
 *         剑指offer第49题
 * 将一个字符串转换成一个整数(实现Integer.valueOf(string)的功能，但是string不符合数字要求时返回0)，要求
   不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0。
 *
 * Input:  字符串
 * Output: 字符串转换成数字
 *
 * Note: 
 * 比较简单，但是细节需要注意

 * author: lcxanhui@163.com
 * time: 2019.6.24
 ******************************************************************************************************/

#include<iostream>
#include<string>
using namespace std;

int StrToInt(string str) {
	if (str.empty())
		return 0;
	bool flag = true;
	if (str[0] == '+')
	{
		flag = true;
		str[0] = '0';   // 注意此处为‘0’
	}
	if (str[0] == '-')
	{
		flag = false;
		str[0] = '0';
	}
	int sum = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i]<'0' || str[i]>'9')
		{
			sum = 0;
			break;
		}
		sum = sum * 10 + str[i] - '0'; //最后一项-‘0’不可缺少
	    if((flag == true && sum > 0x7fffffff) || (flag == false && sum < (signed int)0x80000000))
			sum=0;
	}
	return (flag==true)?sum:(-sum);
}
int main(void)
{
	string str = "-19864646546889";
	//string str = "-1986";
	//string str = "-1986ac";
	int res = StrToInt(str);
	cout << res;
	return 0;
}