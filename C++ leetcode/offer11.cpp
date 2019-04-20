/*****************************************************************************************************
 *         剑指offer第11题
 * 给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
 *
 * Input:   base和exponent
 * Output:  指数幂
 *
 * Note: （需要考虑特殊的边界）
 * 本题考察对边界测试能力，不仅仅考虑到常规的base>0和exponent>0的情况，还要考虑到base为正、负、0以及
   exponent为正、负、0的特殊条件和两者组合。
 *
 * 本次提供两种方法：
 方法1：循环算法，常规，复杂度为O(n);
 方法2：递归算法，类似于Fibonacci数列的拓展知识，利用位运算进行初以2，复杂度O(logn)
        n为偶数，a^n=a^n/2*a^n/2;      n为奇数，a^n=（a^（n-1）/2）*（a^（n-1/2））*a
 * authur: lcxanhui@163.com
 * time: 2019.4.20
 ******************************************************************************************************/

#include<iostream>
using namespace std;

double power(double base, int exponent)
{
	if (base == 0 && exponent == 0)       //特殊情况，0的0次幂无意义
		return -1;
	if (base != 0 && exponent == 0)       //指数为0的情况
		return 1;
	if (exponent == 1)                    //指数为1的情况
		return base;
	if (base == 0 && exponent > 0)        //底为0，指数大于零的情况
		return 0;
	int absexponent = exponent;
	if (exponent < 0)                   // 需要考虑的情况，当指数为负数的情况下取绝对值，然后最后的结果需要求倒数
	{
		absexponent = -exponent;
	}
/********************************************************************
	double result = power(base, absexponent >> 2);     //递归算法
	result *= result; 
	if ((absexponent & 1) == 1)               //奇数的情况
		result *= base;
	if (exponent < 0)
		result = 1 / result;
	return result;
*******************************************************************/
	double result = 1.0;
	for (int i = 1; i <= absexponent; i++)     // 求取指数幂的算法，循环算法的复杂度为O(n)
	{
		result *= base;
	}
	if (exponent < 0)                 //切记要求倒数
		result = 1 / result;
	return result;
}

int main(void)
{
	double base;
	int exponent;
	cin >> base >> exponent;
	double result=1.0;
	result = power(base, exponent);
	cout << result;
	return 0;
}