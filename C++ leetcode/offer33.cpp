/*****************************************************************************************************
 *         ��ָoffer��33��
 * ����һ�����������飬����������������ƴ�������ų�һ��������ӡ��ƴ�ӳ���������������С��һ����
   ������������{3��32��321}�����ӡ���������������ųɵ���С����Ϊ321323��
 *
 * Input:  һά����
 * Output: ����������������ɵ���С����
 *
 * Note: �����ǵ��½��ȽϹ��򣬲����漰���������⣬���ܻ�����������������ַ�����
 * key:�Զ���һ���Ƚϴ�С�ĺ������Ƚ������ַ���s1, s2��С��ʱ���Ƚ�����ƴ���������Ƚ�s1+s2,��s2+s1�Ǹ���
   ���s1+s2����˵��s2Ӧ�÷�ǰ�棬���԰��������s2��Ӧ������s1ǰ�档
 * author: lcxanhui@163.com
 * time: 2019.5.15
 ******************************************************************************************************/
#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include <algorithm>
using namespace std;

//�����ĿҪ��ó��������֣����Խ��Ƚ���ת���ɴӴ�С���򼴿�
   //���У�����ת��Ϊ�ַ�����ʹ�÷������ο����˵Ĵ���
static bool compare(const string &st1, const string &st2)
{
	string s1 = st1 + st2;
	string s2 = st2 + st1;
	return s1 < s2;      //�������У���Ϊ���ھ����������У���
}
string PrintMinNumber(vector<int> numbers)
{
	string res;
	if (numbers.size() <= 0)
		return res;
	vector<string> vec;
	for (int i = 0; i < numbers.size(); i++)
	{
		stringstream ss;        //ʹ�������������ͷ�ļ�Ҫ����#include<sstream>
		ss << numbers[i];      //�������ָ�������
		string s = ss.str();   //ת�����ַ���
		vec.push_back(s);      //���ַ���sѹ��vec��
	}
	//���򣬴���Ƚ�������С��������
	// compare��Ϊ�Ƚ�����sort�������ã���Ϊ���ǵ����ıȽ�������ֵ�Ĵ�С����
	//�Ƚ��������ֱ�ǰ��������ֵ�Ĵ�С������Ҫ��д�Ƚ���
	sort(vec.begin(), vec.end(), compare);
	for (int i = 0; i < vec.size(); i++)
		res.append(vec[i]);        //ƴ���ַ������������С������
	return res;
}

int main(void)
{
	vector<int> numbers{ 3,321,22,43 };
	string result = PrintMinNumber(numbers);
	cout << result;
	return 0;
}