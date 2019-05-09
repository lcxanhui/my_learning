/*****************************************************************************************************
 *         ��ָoffer��28��
 * ����һ���ַ���,���ֵ����ӡ�����ַ������ַ����������С����������ַ���abc,���ӡ�����ַ�a,b,c��������
   �����������ַ���abc,acb,bac,bca,cab��cba��
 *
 * Input:  �ַ���
 * Output: �ַ�����ȫ����
 *
 * Note: �����η�--˼����
 * ���÷��η��ݹ����ȡ�ַ�����ȫ���У�ע�⵱�ַ���������ͬ���ַ�ʱ������Ҫ�жϽ����ַ�ʱ�Ƿ�ͺ������ͬ��
 * author: lcxanhui@163.com
 * time: 2019.5.9
 ******************************************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

void PermutationRecursive(string str, vector<string> &res, int start, int end);
bool HasSame(string &str, int start, int i);

vector<string> Permutation(string str)
{
	vector<string> res;
	if (str.size() == 0)
		return res;
	PermutationRecursive(str, res, 0, str.size());   // �ݹ����
	return res;
}

void PermutationRecursive(string str, vector<string> &res, int start, int end)   //������startλ�����п�����
{
	if (start == end)
		res.push_back(str);
	else
	{
		for (int i = start; i < end; i++)
		{
			if (!HasSame(str, start, i))
			{
				char tmp = str[i];       //������startλ�͵�iλ���ַ�
				str[i] = str[start];
				str[start] = tmp;
				PermutationRecursive(str, res, start + 1, end);
			}
		}
	}
}

bool HasSame(string &str, int start, int i) //��startλ����iλ�Ƿ����ظ����ַ�
{
	for (int j = start; j < i; j++)
	{
		if (str[j] == str[i])
			return true;
	}
	return false;
}

int main(void)
{
	// string str = "abc"; 
	string str="abb";
	vector<string> res;
	res=Permutation(str);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	return 0;
}