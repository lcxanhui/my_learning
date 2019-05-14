/*****************************************************************************************************
 *         ��ָoffer��31��
 * ����һ���������飬������������Ҳ�и�����������һ���������Ķ���������һ�������飬������������ĺ�
   �����ֵ��
 *
 * Input:  һά����
 * Output: ����������ĺ͵����ֵ
 *
 * Note: ���򵥵Ķ�̬�滮����Ŀ��
 * ����һ����A������A������ۼ����Ǹ�����ô����A��ʹ��ֵ��С��A����Ϊ�ۼ�ֵ��
   ��������й��׵ġ����ǰ�����ۼ�ֵ����������Ϊ�к����ܺͣ�total��¼��ǰֵ
 * author: lcxanhui@163.com
 * time: 2019.5.14
 ******************************************************************************************************/
#include<iostream>
#include<vector>
using namespace std;

int FindMaxSumOfArr(vector<int> arr)
{
	int len = arr.size();
	if (len == 0)
		return 0;
	int curSum = 0;   // ��ǰ�ĺ�
	int result = arr[0];   // ���յĺ�
	for (int i = 0; i < len; i++)
	{
		//�����ǰ�ĺ�С��0���򽫵�ǰ������Ϊ�����еĵ�һ���������򣬼������
		if (curSum <= 0)
			curSum = arr[i];
		else
			curSum += arr[i];
		//��ǰ�ͱ�����Ҫ�õ��ĺʹ� �����յĺ�����Ϊ��ǰ�ĺ�
		if (curSum > result)
			result = curSum;
	}
	return result;
}

int main(void)
{
	vector<int> arr{ 1,-2,3,10,-4,7,2,-5 };
	int result = FindMaxSumOfArr(arr);
	cout << result;
	return 0;
}