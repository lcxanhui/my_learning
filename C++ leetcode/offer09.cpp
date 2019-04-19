/*****************************************************************************************************
 *         ��ָoffer��9��
 * ��Fibonacci���еĵ�n��
 *
 * Input: number
 * Output: Fibonacci����sum
 *
 * Note:  ��ѭ�����ǵݹ���������֣�
 * �ݹ��㷨�����ѭ������̣�����ʱ�临�Ӷ���n��ָ������������������ȱ�㣺1������������Ҫ����ʱ��Ϳռ䣬ÿ��
 �������ö���Ҫ���ڴ�ջ�з���ռ䱣����������ص�ַ����ʱ������ 2���ݹ��кܶ���㶼���ظ��ģ�3������ջ�������
 ���ò㼶̫��ʱ�������׳��֡�
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