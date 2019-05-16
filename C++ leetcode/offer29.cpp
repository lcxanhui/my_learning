/*****************************************************************************************************
 *         ��ָoffer��29��
 * ��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡���������һ������Ϊ9������{1,2,3,2,
   2,2,5,4,2}����������2�������г�����5�Σ��������鳤�ȵ�һ�룬������2����������������0��
 *
 * Input:   ����
 * Output:  ���ִ���������
 *
 * Note: �����ֽⷨ����O(n)��
 * ����з������������֣��������ֵĴ����������������ֳ��ֵĴ����ͻ�Ҫ�ࡣ�ڱ�������ʱ��������ֵ��
   һ��������һ�����֣�һ�Ǵ�����������һ������ʱ��������֮ǰ�����������ͬ���������1�����������1��
   ������Ϊ0���򱣴���һ�����֣�����������Ϊ1����������������������ּ�Ϊ����Ȼ�����ж����Ƿ�����������ɡ�
 *
 * �����ṩ���ַ�����
 ����1��������������м�����Ϊresult
 ����2������з������������֣��������ֵĴ����������������ֳ��ֵĴ����ͻ�Ҫ�ࡣ�ڱ�������ʱ��������ֵ��
   һ��������һ�����֣�һ�Ǵ�����������һ������ʱ��������֮ǰ�����������ͬ���������1�����������1��
   ������Ϊ0���򱣴���һ�����֣�����������Ϊ1����������������������ּ�Ϊ����Ȼ�����ж����Ƿ�����������ɡ�
 * author: lcxanhui@163.com
 * time: 2019.5.12
 ******************************************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

int MoreThanHalfNum(vector<int> numbers) {
	int len = numbers.size();
	if (len <= 0)
		return 0;
	int num = numbers[0], count = 1;
	for (int i = 1; i < len; i++)
	{
		// ����ÿ��Ԫ�أ�����¼����������ǰһ��Ԫ����ͬ���������1�����������1
		if (numbers[i] == num)
			count++;
		else
			count--;
		if (count < 0)
		{
			num = numbers[i];
			count = 1;
		}
	}
	// Verifying
	count = 0;
	for (int i = 0; i < len; i++)
	{
		if (numbers[i] == num)
			count++;
	}
	if (count * 2 > len)
		return num;
	return num;
}

int main()
{
	vector<int> numbers;
	numbers.push_back(1);
	numbers.push_back(2);
	numbers.push_back(3);
	numbers.push_back(5);
	numbers.push_back(2);
	numbers.push_back(2);
	int result = MoreThanHalfNum(numbers);
	return result;
}