/*****************************************************************************************************
 *         ��ָoffer��36��
 * �������е��������֣����ǰ��һ�����ִ��ں�������֣����������������һ������ԡ�����һ������,���
   ��������е�����Ե�����P������P��1000000007ȡģ�Ľ������� �����P%1000000007
 *
 * Input:  һά����
 * Output: ����Եĸ���
 *
 * Note: �����ù鲢����˼·�Ƚ��ѣ�ʱ�临�Ӷ�O(nlogn),�ռ临�Ӷ�O(n),�Կռ任ȡʱ�䣩
 * ����˼·�μ�
     https://www.nowcoder.com/questionTerminal/96bd6684e04a44eb80e6a68efc0ec6c5
   ��һ����˼·����

 * author: lcxanhui@163.com
 * time: 2019.5.18
 ******************************************************************************************************/

#include<iostream>
#include<vector>

using namespace std;
long long ReservePairs(vector<int> &data, vector<int> &copy, int start, int end)
{
	if (start == end)
	{
		copy[start] = data[start];
		return 0;
	}
	//�������������зֿ�
	int len = (end - start) / 2;

//���ǹ������copy��data���ݹ鴫��ʵ����Ҫ��copy���Ѿ�����ã����룬data������������
	//�ݹ�ֱ�ͳ�����������ܵ���������
	long long left = ReservePairs(copy, data, start, start + len);
	long long right = ReservePairs(copy, data, start+len+1, end);
//��ߵ�ָ��ָ�����һ��
	int i = start + len;
//�ұߵ�ָ��ָ������Ľ�β
	int j = end;
	int indexcopy = end;
	long long count = 0;
	while (i >= start && j >= start + len + 1)
	{
//���ָ��ָ��������ұ�ָ��ָ�����������ұ�ָ��ǰ������Ҫ��
		if (data[i] > data[j])
		{
			copy[indexcopy--] = data[i--];
			count = count + (j - len - start -1) +1;
		}
		else
		{
			copy[indexcopy--] = data[j--];
		}
	}
	for(;i>=start;i--)
		copy[indexcopy--] = data[i];
	for (; j >= start + len + 1; j--)
		copy[indexcopy--] = data[j];
// ���ؽ��
	return left + right + count;
}

int InversePairs(vector<int> data)
{
	int len = data.size();
	if (len <= 0)
		return 0;
	vector<int> copy;
	for (int i = 0; i < len; i++)
		copy.push_back(data[i]);
	long long count = ReservePairs(data, copy, 0, len - 1);
	return (count % 1000000007);
}

int main(void)
{
	vector<int> data{ 7,5,6,4 };
	int count = InversePairs(data);
	cout << count;
	return 0;
}