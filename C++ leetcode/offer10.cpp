/*****************************************************************************************************
 *         剑指offer第10题
 * 输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
 *
 * Input:   整数	
 * Output:  1的个数
 *
 * Note: （位运算）
 * 本次提供两种方法：
 方法1：构造一个flag，与原数进行与运算，判断最后一位是否为1，再将flag左移一位，再与原数进行与运算，判断
        倒数第二位是否为1，以此类推；
 方法2：将原数进行减一操作，然后将两个数进行与运算，则一个整数二进制表示中有多少个1，就可以进行多少次这样的操作
 * authur: lcxanhui@163.com
 * time: 2019.4.20
 ******************************************************************************************************/

#include<iostream>
using namespace std;

int numberOf1(int n)
{
/**	int count = 0;
	unsigned int flag = 1;
	while (flag)
	{
		if (flag&n)
			count++;
		flag = flag << 1;
	}
	return count;**/
	int count = 0;
	while (n != 0)
	{
		count++;
		n = (n - 1)&n;
	}
	return count;
}

int main(void)
{
	int n;
	cin >> n;
	int result;
	result = numberOf1(n);
	cout << result;
}