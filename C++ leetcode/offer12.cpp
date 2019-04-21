/*****************************************************************************************************
 *         ��ָoffer��12��
 * ��������n����˳���ӡ����1������nλʮ����������������3�����ӡ���1��2��3һֱ������3λ����999
 *
 * Input:  ����n
 * Output: ��1������nλʮ������
 *
 * Note:  ���������⣬�����ó��������������long long�洢���ݣ�
 * �����ַ������洢�������Ա�ʾ�������ַ����ĳ���Ҫ���ǵ����һλΪ'\0',���Ҵ�ӡ�ĺ�������ֱ��printf,Ӧ����
   ��ӡ�ַ���ǰ�����0���ֵ�Ӱ�죻ͬʱ�����Ҫɾ���ַ������ͷ��ڴ档
 * author: lcxanhui@163.com
 * time: 2019.4.21
 ******************************************************************************************************/

#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

void Print1ToMaxOfDigits(int n);        // ��ӡ1������nλ��
void PrintNumRecursively(char* number, int length, int index);  // �ݹ��㷨��ӡ���ֺ���
void PrintNum(char* number);         //��ӡ���ֺ���

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
	char *number = new char[n + 1];     //�����ַ������洢Ҫ��ӡ�����֣��ַ�������Ϊn+1,����'\0'�Ĵ���
	number[n] = '\0';                   
	for (int i = 0; i < 10; i++)       // ����ÿһλ������Ϊ0-9����˽�ÿһλ0-9����һ��
	{
		number[0] = i + '0';
		PrintNumRecursively(number,n,0);   //�ݹ��㷨���ú������ɽ��
	}

	delete[]number;       //�ͷ��ڴ棬�ز�����
}


void PrintNumRecursively(char* number,int length,int index)
{
	if (index == length - 1)      // �ݹ���������������Ѿ����������ֵ����һλ
	{
		PrintNum(number);
		return;
	}
	for (int i = 0; i < 10; i++)
	{
		number[index + 1] = i + '0';      //�ݹ��㷨����һλ
		PrintNumRecursively(number, length, index + 1);
	}
}

void PrintNum(char* number)    //����Ĵ�ӡ����ǰ�������ɸ�0������006֮��ģ����Զ����µĴ�ӡ��������ʾ
{
	bool isbegin0 = true;      //�����Ҫ��ӡ�����Ǵ�0��ʼ��
	int nLength = strlen(number);
	for (int i = 0; i < nLength; i++)
	{
		if (isbegin0 && number[i] != '0')     // �������Ǵ�0��ʼ�ģ����ǵ�iλ��Ϊ0
			isbegin0 = false;
		if (!isbegin0)      //��ʼλΪfalse���������ֲ��Ǵ�0��ʼ��
			printf("%c", number[i]);
	}
}