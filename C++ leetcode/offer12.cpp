/*****************************************************************************************************
 *         剑指offer第12题
 * 输入数字n，按顺序打印出从1到最大的n位十进制数。比如输入3，则打印输出1、2、3一直到最大的3位数即999
 *
 * Input:  数字n
 * Output: 从1到最大的n位十进制数
 *
 * Note:  （大数问题，不能用常规的数据类型如long long存储数据）
 * 利用字符串来存储数据用以表示大数，字符串的长度要考虑到最后一位为'\0',并且打印的函数不能直接printf,应考虑
   打印字符的前面带有0数字的影响；同时，最后要删除字符串以释放内存。
 * author: lcxanhui@163.com
 * time: 2019.4.21
 ******************************************************************************************************/

#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

void Print1ToMaxOfDigits(int n);        // 打印1到最大的n位数
void PrintNumRecursively(char* number, int length, int index);  // 递归算法打印数字函数
void PrintNum(char* number);         //打印数字函数

int main(void)
{
	int n;
	cin >> n;
	Print1ToMaxOfDigits(n);
	return 0;
}

void Print1ToMaxOfDigits(int n)
{
	if (n <= 0)
		return;
	char *number = new char[n + 1];     //利用字符串来存储要打印的数字，字符串长度为n+1,由于'\0'的存在
	number[n] = '\0';                   
	for (int i = 0; i < 10; i++)       // 由于每一位的数字为0-9，因此将每一位0-9排列一遍
	{
		number[0] = i + '0';
		PrintNumRecursively(number,n,0);   //递归算法调用函数生成结果
	}

	delete[]number;       //释放内存，必不可少
}


void PrintNumRecursively(char* number,int length,int index)
{
	if (index == length - 1)      // 递归结束的条件，即已经设置了数字的最后一位
	{
		PrintNum(number);
		return;
	}
	for (int i = 0; i < 10; i++)
	{
		number[index + 1] = i + '0';      //递归算法到上一位
		PrintNumRecursively(number, length, index + 1);
	}
}

void PrintNum(char* number)    //常规的打印会在前面有若干个0，比如006之类的，所以定义新的打印函数来显示
{
	bool isbegin0 = true;      //假设该要打印数字是从0开始的
	int nLength = strlen(number);
	for (int i = 0; i < nLength; i++)
	{
		if (isbegin0 && number[i] != '0')     // 该数字是从0开始的，但是第i位不为0
			isbegin0 = false;
		if (!isbegin0)      //开始位为false，即改数字不是从0开始的
			printf("%c", number[i]);
	}
}