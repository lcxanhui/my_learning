/*****************************************************************************************************
 *         ��ָoffer��42-1��
 * ��Ŀ����
 * �������һ����Ա��Fish��ÿ���糿���ǻ�����һ��Ӣ����־��дЩ�����ڱ����ϡ�ͬ��Cat��Fishд��������
   ����Ȥ����һ������Fish������������ȴ������������˼�����磬��student. a am I������������ʶ������һ�
   ԭ���Ѿ��ӵ��ʵ�˳��ת�ˣ���ȷ�ľ���Ӧ���ǡ�I am a student.����
 *
 * Input:  �ַ���
 * Output: ��ת����ַ���
 *
 * Note: ���������շ�ת�ַ����Ĳ������Ǹ����ַ��������Ļ�ʯ��
 *  ���Ƚ����е��ַ����з�ת���ٽ�ÿ�����ʽ��з�ת�����ݿո���ȷ�����ʵ���ʼ����ֹλ��
 * author: lcxanhui@163.com
 * time: 2019.5.30
 ******************************************************************************************************/
#include<iostream>
#include<string>
using namespace std;


// ��ת�ַ����ľ�����룬����
void Reverse(string& str, int begin, int end)
{
	if (begin <0 || end < 0)
		return;
	while(begin < end)    // �ж�����
	{
		char temp;
		temp = str[begin];
		str[begin] = str[end];
		str[end] = temp;
		begin++;
		end--;
	}
}

string ReverseSentence(string str)
{
	if (str.size() <= 1)
		return str;
	int begin = 0, end = 0;
	//������ַ������ܳ���
	while (str[end] != '\0')
		end++;
	//��ʱendָ��\0λ��Ҫ��1ָ��ǰһλ
	end--;
	//�Ƚ������ַ������з�ת
	Reverse(str, begin, end);

	//������ַ�����ĳ�����ʽ��з�ת
	begin = end = 0;

	while (str[begin] != '\0')   // �ж�ѭ������
	{
		if (str[begin] == ' ')    // ���begin�ո�λ��ʱ����begin��end����һ
		{
			begin++;
			end++;
		}
		else if (str[end] == ' ' || str[end] == '\0')  //���end�������ո����\0ʱ���򽫸õ��ʵ�ǰ����з�ת
		{
			Reverse(str, begin, --end);    //ע��˴����ȶ�end-1��ʹ����Ϊ�ո�ǰһλ�ٽ��з�ת
			begin = ++end;   //��ʱ�ö����ĵ����Ѿ���ת��ϣ�Ȼ��begin��Ϊend����Ϊ�ո�ʱ���ֵ���ٽ�����һ������
		}
		else
			end++;
	}
	return str;
}

int main()
{
	string str = "I am a student.";
	string res = ReverseSentence(str);
	cout << res;
	return 0;
}