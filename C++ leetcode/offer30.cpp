/*****************************************************************************************************
 *         剑指offer第30题
 * 输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。
 *
 * Input:  一维数组
 * Output: k个和最小的一维矩数组
 *
 * Note: 
 * 四种解决方案
   1.全排序  O(nlogn)
   2.基于partition的快速排序  O(n)
   3.最大堆排序     O(nlogk)
   4.红黑树：multiset集合   O(nlogk)
   最后两中适用于海量数据的情形，且不改变原数组
 * author: lcxanhui@163.com
 * time: 2019.5.13
 ******************************************************************************************************/
#include<iostream>
#include<vector>
#include <algorithm>
#include <functional>
using namespace std;

vector<int> MinKNum(vector<int> input, int k)
{
	int len = input.size();
	vector<int> res;
	if (len == 0 || k <= 0 || k > len)
		return res;
//最普遍的做法  sort(input.begin(),input.end()); 排序之后取前k个数
//for (int i = 0; i < k; i++)
//res.push_back(input[i]);
	for (int i = 0; i < k; i++)
		res.push_back(input[i]);
	//根据指定的迭代器区间以及一个可选的比较函数，来创建一个heap.O(N)
	make_heap(res.begin(), res.end());
	for (int i = k; i < len; i++)
	{
		if (input[i] < res[0])
		{
			//弹出heap顶元素, 将其放置于区间末尾.O(logN)
			pop_heap(res.begin(), res.end());
			res.pop_back();
			res.push_back(input[i]);
			//把指定区间的最后一个元素插入到heap中.O(logN)
			push_heap(res.begin(), res.end());
		}
	}
	//堆排序算法，通常通过反复调用pop_heap来实现.N*O(logN)
	sort_heap(res.begin(), res.end());
	return res;
}

int main(void)
{
	vector<int> input{ 6, 1, 2, 5, 8, 4 };
	int k = 3;
	vector<int> res;
	res = MinKNum(input, k);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	return 0;
}