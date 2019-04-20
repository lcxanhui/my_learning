/*****************************************************************************************************
 *         ��ָoffer��11��
 * ����һ��double���͵ĸ�����base��int���͵�����exponent����base��exponent�η���
 *
 * Input:   base��exponent
 * Output:  ָ����
 *
 * Note: ����Ҫ��������ı߽磩
 * ���⿼��Ա߽�������������������ǵ������base>0��exponent>0���������Ҫ���ǵ�baseΪ��������0�Լ�
   exponentΪ��������0������������������ϡ�
 *
 * �����ṩ���ַ�����
 ����1��ѭ���㷨�����棬���Ӷ�ΪO(n);
 ����2���ݹ��㷨��������Fibonacci���е���չ֪ʶ������λ������г���2�����Ӷ�O(logn)
        nΪż����a^n=a^n/2*a^n/2;      nΪ������a^n=��a^��n-1��/2��*��a^��n-1/2����*a
 * authur: lcxanhui@163.com
 * time: 2019.4.20
 ******************************************************************************************************/

#include<iostream>
using namespace std;

double power(double base, int exponent)
{
	if (base == 0 && exponent == 0)       //���������0��0����������
		return -1;
	if (base != 0 && exponent == 0)       //ָ��Ϊ0�����
		return 1;
	if (exponent == 1)                    //ָ��Ϊ1�����
		return base;
	if (base == 0 && exponent > 0)        //��Ϊ0��ָ������������
		return 0;
	int absexponent = exponent;
	if (exponent < 0)                   // ��Ҫ���ǵ��������ָ��Ϊ�����������ȡ����ֵ��Ȼ�����Ľ����Ҫ����
	{
		absexponent = -exponent;
	}
/********************************************************************
	double result = power(base, absexponent >> 2);     //�ݹ��㷨
	result *= result; 
	if ((absexponent & 1) == 1)               //���������
		result *= base;
	if (exponent < 0)
		result = 1 / result;
	return result;
*******************************************************************/
	double result = 1.0;
	for (int i = 1; i <= absexponent; i++)     // ��ȡָ���ݵ��㷨��ѭ���㷨�ĸ��Ӷ�ΪO(n)
	{
		result *= base;
	}
	if (exponent < 0)                 //�м�Ҫ����
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