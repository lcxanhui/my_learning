/*****************************************************************************************************
 *         剑指offer第9题
 * 求Fibonacci数列的第n项
 *
 * Input: number
 * Output: Fibonacci数列sum
 *
 * Note:  （循环而非递归的优劣体现）
 * 递归算法相较于循环代码短，但是时间复杂度以n的指数增长，并且有以下缺点：1、函数调用需要消耗时间和空间，每次
 函数调用都需要在内存栈中分配空间保存参数、返回地址和临时变量； 2、递归中很多计算都是重复的；3、调用栈溢出，当
 调用层级太多时，很容易出现。
 * authur: lcxanhui@163.com
 * time: 2019.4.19
 ******************************************************************************************************/

#include<iostream>
using namespace std;

long long Fibonacci(long long number)
{
	if (number <= 0)
		return 0;
	else if (number == 1)
		return 1;
	long long f1 = 0, f2 = 1;
	long long result = 0;
	for (long long  i = 1; i <= number; i++)
	{
		result = f1 + f2;
		f1 = f2;
		f2 = result;
	}
	return result;
}

int main(void)
{
	long long number;
	cin >> number;
	long long result;
	result = Fibonacci(number);
	cout << result;

	return 0;
}