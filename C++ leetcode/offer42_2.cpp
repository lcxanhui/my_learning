/*****************************************************************************************************
 *         ��ָoffer��42-2��
 * ��Ŀ����
 * ���ַ���ģ�����ָ���������������һ���������ַ�����S���������ѭ������Kλ���������������磬
   �ַ�����S=��abcXYZdef��,Ҫ�����ѭ������3λ��Ľ��������XYZdefabc��
 *
 * Input:  �ַ����ͷ�ת��λ��
 * Output: ��ת����ַ���
 *
 * Note: ���������շ�ת�ַ����Ĳ������Ǹ����ַ��������Ļ�ʯ��
 *  ���Ƚ�ǰN���ַ������з�ת���ٽ���len-N+1���ַ������з�ת��������е��ַ����з�ת��
    ������ѧ��YX=��XTYT��T ������TΪת��
 * author: lcxanhui@163.com
 * time: 2019.5.30
 ******************************************************************************************************/
#include<iostream>
#include<string>
using namespace std;


// ��ת�ַ����ľ�����룬����
void Reverse(string& str, int begin, int end)
{
	if (begin < 0 || end < 0)
		return;
	while (begin < end)    // �ж�����
	{
		char temp;
		temp = str[begin];
		str[begin] = str[end];
		str[end] = temp;
		begin++;
		end--;
	}
}

string LeftRotateString(string str,int n)
{
	int len = str.size();
	if (len <= 0 || n<=0)
		return str;
	if (n > len)
		n = n % len;   //���λ��N����len������12>9�������������Ϊ3�����ַ����ĵ�3��λ�ý��з�ת
	string& temp = str;
	Reverse(temp, 0, n - 1);
	Reverse(temp, n, len - 1);
	Reverse(temp, 0, len - 1);
	return str;
}

int main()
{
	string str = "I am a student.";
	int n;
	cin >> n;
	string res = LeftRotateString(str, n);
	cout << res;
	return 0;
}