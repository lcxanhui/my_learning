/*****************************************************************************************************
 *         ��ָoffer��4��
 *��ʵ��һ����������һ���ַ����е�ÿ���ո��滻�ɡ�%20�������磬���ַ���ΪWe Are Happy.�򾭹��滻
  ֮����ַ���ΪWe%20Are%20Happy

 * Input:  �ַ���str
 * Output: �滻����ַ���
 *
 * Note: ��ע���ڴ����������
 * �ȶ��ַ������б�������ȡ�ַ����ĳ����Լ��ո���������ٹ����µ��ַ����ĳ��ȣ�����ԭ�ַ������
 * ���б����������滻
 ******************************************************************************************************/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void replaceSpace(char *str, int length) {
	if (str == NULL && length < 0)
		return;
	int oldlen = strlen(str);          // strlen������ȡ�ַ����ĳ���
	int blank = 0;
	for (int i = 0; i < oldlen; i++)
	{
		if (str[i] == ' ')
			blank++;
	}
	int newlen = oldlen + blank * 2;
	while (newlen > oldlen && newlen > 0) {    // ѭ������
		for (int j = oldlen; j >= 0; j--)    // ��ԭ�ַ��������ʼ����
		{
			if (str[j] == ' ')
			{
				str[newlen--] = '0';
				str[newlen--] = '2';
				str[newlen--] = '%';
			}
			else
				str[newlen--] = str[j];
		}
	}
}

int main()
{
	char str[20]="a d ef c";

	replaceSpace(str, 20);
	cout << str << endl;

	system("pause");
	return 0;
}