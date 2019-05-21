/*****************************************************************************************************
 *         ��ָoffer��38��
 * ͳ��һ�����������������г��ֵĴ���
 *
 * Input:  һά�����K
 * Output: ������K�ĸ���
 *
 * Note: �����ַ����ң�
 * ���ڸ��������������飬��˿������ö��ַ����ҡ�
   ���ö��ַ��ֱ��õ�һ��K�����һ��K��λ�ü��ɣ��ؼ����ڶԶ��ַ����ҵ����ճ̶�
 * author: lcxanhui@163.com
 * time: 2019.5.21
 ******************************************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

//���ö��ַ���ȡ��һ��K��λ�ã��ݹ���ã�
int GetfirstK(vector<int> &data, int k, int start, int end)
{
	if (start > end)
		return -1;
	int mid = start + (end - start) / 2;    //���ַ�
	if (data[mid] > k) 
		return GetfirstK(data, k, start, mid - 1);
	else if (data[mid] < k)
		return GetfirstK(data, k, mid + 1, end);
	else if (mid - 1 >= 0 && data[mid - 1] == k)
		return GetfirstK(data, k, start, mid - 1);
	else
		return mid;
}

//// ���ö��ַ���ȡ���һ��K��λ�ã��ݹ���ã�
//int GetlastK(vector<int> &data, int k, int start, int end)
//{
//	if (start > end)
//		return -1;
//	int mid = start + (end - start) / 2;
//	if (data[mid] > k)
//		return GetlastK(data, k, start, mid - 1);
//	else if (data[mid] < k)
//		return GetlastK(data, k, mid + 1, end);
//	else if (mid + 1 < data.size() && data[mid + 1] == k)
//		return GetlastK(data, k, mid+1, end);
//	else
//		return mid;
//}

//�ǵݹ���õķ���������һ��K��λ��
int GetlastK(vector<int> &data, int k, int start, int end)
{
	if (start > end)
		return -1;
	int mid = start + (end - start) / 2;
	while (start <= end)
	{
		if (data[mid] > k)
			end = mid - 1;
		else if (data[mid] < k)
			start = mid + 1;
		else if (mid + 1 < data.size() && data[mid + 1] == k)
			start = mid + 1;
		else
			return mid;
		mid = start + (end - start) / 2;
	}
	return -1;
}


int GetNumberOfK(vector<int> data, int k)
{
	if (data.size() <= 0)
		return 0;
	int end = data.size() - 1;
	int firstK = GetfirstK(data, k, 0, end);  //�����������������ֱ��ȡK������λ��
	int lastK = GetlastK(data, k, 0, end);
	if (firstK != -1 && lastK != -1)
		return lastK - firstK + 1;     // ����K�ĸ���
	return 0;
}

int main(void)
{
	vector<int> data{ 3,3,3,3,3,4};
	int count = GetNumberOfK(data,4);
	cout << count;
	return 0;
}