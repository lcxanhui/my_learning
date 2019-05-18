/*****************************************************************************************************
 *         剑指offer第36题
 * 在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组,求出
   这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 即输出P%1000000007
 *
 * Input:  一维数组
 * Output: 逆序对的个数
 *
 * Note: （利用归并排序思路比较难，时间复杂度O(nlogn),空间复杂度O(n),以空间换取时间）
 * 具体思路参见
     https://www.nowcoder.com/questionTerminal/96bd6684e04a44eb80e6a68efc0ec6c5
   第一个的思路分析

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
	//将左右两个进行分开
	int len = (end - start) / 2;

//这是故意调换copy和data，递归传入实参需要把copy（已经排序好）传入，data当作辅助数组
	//递归分别统计左右数组总的逆序数组
	long long left = ReservePairs(copy, data, start, start + len);
	long long right = ReservePairs(copy, data, start+len+1, end);
//左边的指针指向最后一个
	int i = start + len;
//右边的指针指向数组的结尾
	int j = end;
	int indexcopy = end;
	long long count = 0;
	while (i >= start && j >= start + len + 1)
	{
//左边指针指向的数比右边指针指向的数大，则比右边指针前的数都要大
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
// 返回结果
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