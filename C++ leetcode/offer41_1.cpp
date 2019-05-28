/*****************************************************************************************************
 *         ��ָoffer��41-1��
 * ��Ŀ����
 * ����һ����������������һ������S���������в�����������ʹ�����ǵĺ�������S������ж�����ֵĺ͵���S��
   ����������ĳ˻���С�ġ�
 *
 * Input:  һά�����sum
 * Output: ��Ϊsum��������������֣��ҳ˻���С
 *
 * Note: ���򵥵�˫ָ�뷨��
 *  1.left��ͷ��rightָ���β
    2.�����С��sum��˵��̫С�ˣ�left����Ѱ�Ҹ������
    3.����ʹ���sum��˵��̫���ˣ�right����Ѱ�Ҹ�С����
    4.����ȣ���left��right��������
 * author: lcxanhui@163.com
 * time: 2019.5.28
 ******************************************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

vector<int> FindNumbersWithSum(vector<int> array, int sum)
{
	int len = array.size();
	vector<int> res;
	if (len <= 1)
		return res;
	int start = 0, end = len - 1;
	while (start < end)
	{
		if (array[start] + array[end] == sum)
		{
			res.push_back(array[start]);
			res.push_back(array[end]);
			break;
		}
		else if (array[start] + array[end] < sum)
			start++;
		else
			end--;
	}
	return res;
}

int main(void) {
	vector<int> array = { 1,2,4,7,13,14 };
	int sum = 15;
	vector<int> res = FindNumbersWithSum(array, sum);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	return 0;
}