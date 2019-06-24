/*****************************************************************************************************
 *         剑指offer第47题
 * 写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。
 *
 * Input:  两个整数
 * Output: 两数之和
 *
 * Note:（三步走战略） 
 1.先不考虑进位，即对两数求取异或（相同为0，不同为1，符合加法运算）
 2.考虑进位，即两数 与 运算，在左移一位
 3.n1&n2是查看有没有进位位了，如果有，需要重复step1、step2；
   如果没有，保留n1、n2上二进制为1的部分，用或将之合为一个数

 * author: lcxanhui@163.com
 * time: 2019.6.24
 ******************************************************************************************************/

#include<iostream>
#include<string>
using namespace std;

int Sum(int num1, int num2)
{
	int carry, sum;
	do {
		sum = num1 ^ num2;   //先不考虑进位，即对两数求取异或（相同为0，不同为1，符合加法运算）
		carry = (num1&num2) << 1;  // 考虑进位，即两数 与 运算，在左移一位

		num1 = sum;
		num2 = carry;
	} while (num2 != 0);    //进位为1才考虑，不为1时不进行
	return num1;
}

int main()
{
	int num1, num2;
	cin >> num1 >> num2;
	int sum = Sum(num1, num2);
	cout << sum;
	return 0;
}
