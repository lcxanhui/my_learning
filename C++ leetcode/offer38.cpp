/*****************************************************************************************************
 *         剑指offer第38题
 * 统计一个数字在排序数组中出现的次数
 *
 * Input:  一维数组和K
 * Output: 数组中K的个数
 *
 * Note: （二分法查找）
 * 由于该数组是排序数组，因此考虑运用二分法查找。
   利用二分法分别获得第一个K和最后一个K的位置即可，关键在于对二分法查找的掌握程度
 * author: lcxanhui@163.com
 * time: 2019.5.21
 ******************************************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

//利用二分法获取第一个K的位置（递归调用）
int GetfirstK(vector<int> &data, int k, int start, int end)
{
	if (start > end)
		return -1;
	int mid = start + (end - start) / 2;    //二分法
	if (data[mid] > k) 
		return GetfirstK(data, k, start, mid - 1);
	else if (data[mid] < k)
		return GetfirstK(data, k, mid + 1, end);
	else if (mid - 1 >= 0 && data[mid - 1] == k)
		return GetfirstK(data, k, start, mid - 1);
	else
		return mid;
}

//// 利用二分法获取最后一个K的位置（递归调用）
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

//非递归调用的方法获得最后一个K的位置
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
	int firstK = GetfirstK(data, k, 0, end);  //调用上述两个函数分别获取K的两个位置
	int lastK = GetlastK(data, k, 0, end);
	if (firstK != -1 && lastK != -1)
		return lastK - firstK + 1;     // 返回K的个数
	return 0;
}

int main(void)
{
	vector<int> data{ 3,3,3,3,3,4};
	int count = GetNumberOfK(data,4);
	cout << count;
	return 0;
}