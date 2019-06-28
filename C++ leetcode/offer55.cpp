/*****************************************************************************************************
 *                      ��ָoffer��55��
 * ��ʵ��һ�����������ҳ��ַ����е�һ��ֻ����һ�ε��ַ������磬�����ַ�����ֻ����ǰ�����ַ�"go"ʱ��
   ��һ��ֻ����һ�ε��ַ���"g"�����Ӹ��ַ����ж���ǰ�����ַ���google"ʱ����һ��ֻ����һ�ε��ַ���"l"��
 *
 * Input:  �ַ���
 * Output: �ַ����еĵ�һ�����ظ�������
 *
 * Note:���ó��������⣬���Բ���ͨ����
	�������ַ����У��ַ�ֻ��һ������һ���Ĵ��ַ����г����������Ҫ����һ�����������������ַ������ַ�����
	��λ�ã���hash����Գ䵱�ý�ɫ����������ÿ���ַ�ռ��8�ֽڿռ䣬��˿�����256��С��hash����б��棬����
	ͳ��ÿ���ַ���hash���е���Ŀ�����ص�һ��ֻ����һ�ε��ַ���

 * author: lcxanhui@163.com
 * time: 2019.6.28
 ******************************************************************************************************/

#include<iostream>
#include<string>
#include<functional> 
#include<limits>
using namespace std;

class Solution {
public:
	void Insert(char ch)
	{
		s += ch;  //�����������������ch�ַ�����ch�ַ�����s�е�ĳ��λ��
		hash[ch]++;  
	}
	char firstAppearOnes() {
		for (int i = 0; i < s.size(); i++)
		{
			if (hash[s[i] == 1])   //���hash���ĳ��λ��Ϊ1���򷵻ظ��������򷵻ء�#��
				return s[i];
		}
		return '#';
	}
private:
	// �����ݷ�װ���������ʵ�ֶ����ݵķ�װ��
	string s;
	char hash[256] = { 0 };   // ����charռ��1���ֽڣ���˿�����256����С��hash����г�ʼ��
};

void Test(const char* testName, Solution chars, char expected)
{
	if (testName != NULL)
		printf("%s begins: ", testName);

	if (chars.firstAppearOnes() == expected)
		printf("Passed.\n");
	else
		printf("FAILED.\n");
}

int main(int argc, char* argv[])
{
	Solution chars;

	Test("Test1", chars, '\0');

	chars.Insert('g');
	Test("Test2", chars, 'g');

	chars.Insert('o');
	Test("Test3", chars, 'g');

	chars.Insert('o');
	Test("Test4", chars, 'g');

	chars.Insert('g');
	Test("Test5", chars, '\0');

	chars.Insert('l');
	Test("Test6", chars, 'l');

	chars.Insert('e');
	Test("Test7", chars, 'l');

	return 0;
}