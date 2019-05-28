/*****************************************************************************************************
 *         剑指offer第41-1题
 * 题目描述
 * 输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，如果有多对数字的和等于S，
   输出两个数的乘积最小的。
 *
 * Input:  一维数组和sum
 * Output: 和为sum的数组的两个数字，且乘积最小
 *
 * Note: （简单的双指针法）
 *  1.left开头，right指向结尾
    2.如果和小于sum，说明太小了，left右移寻找更大的数
    3.如果和大于sum，说明太大了，right左移寻找更小的数
    4.和相等，把left和right的数返回
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