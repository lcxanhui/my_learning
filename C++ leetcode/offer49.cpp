/*****************************************************************************************************
 *         ��ָoffer��49��
 * ��һ���ַ���ת����һ������(ʵ��Integer.valueOf(string)�Ĺ��ܣ�����string����������Ҫ��ʱ����0)��Ҫ��
   ����ʹ���ַ���ת�������Ŀ⺯���� ��ֵΪ0�����ַ�������һ���Ϸ�����ֵ�򷵻�0��
 *
 * Input:  �ַ���
 * Output: �ַ���ת��������
 *
 * Note: 
 * �Ƚϼ򵥣�����ϸ����Ҫע��

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
		str[0] = '0';   // ע��˴�Ϊ��0��
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
		sum = sum * 10 + str[i] - '0'; //���һ��-��0������ȱ��
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