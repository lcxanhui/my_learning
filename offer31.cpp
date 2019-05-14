/*****************************************************************************************************
 *         剑指offer第31题
 * 输入一个整数数组，数组中有正数也有负数。数组中一个或连续的多个整数组成一个子数组，求所有子数组的和
   的最大值。
 *
 * Input:  一维数组
 * Output: 所有子数组的和的最大值
 *
 * Note: （简单的动态规划的题目）
 * 对于一个数A，若是A的左边累计数非负，那么加上A能使得值不小于A，认为累计值对
   整体和是有贡献的。如果前几项累计值负数，则认为有害于总和，total记录当前值
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
	int curSum = 0;   // 当前的和
	int result = arr[0];   // 最终的和
	for (int i = 0; i < len; i++)
	{
		//如果当前的和小于0，则将当前和设置为数组中的第一个数，否则，继续求和
		if (curSum <= 0)
			curSum = arr[i];
		else
			curSum += arr[i];
		//当前和比最终要得到的和大， 则最终的和设置为当前的和
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