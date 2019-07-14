/*****************************************************************************************************
 *         剑指offer第64题
 * 如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间
   的数值。如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。我们使用
   Insert()方法读取数据流，使用GetMedian()方法获取当前读取数据的中位数。
 *
 * Input:  数据流
 * Output: 数据流的中位数----注意奇偶性
 *
 * Note: （时间复杂度O(nlogn),空间复杂度O(1),利用最大堆和最小堆实现）
 * 利用优先队列实现最大堆最小堆，如果不声明greater<int>,的话，默认为最大堆，即less<int>()
 
		因为要求的是中位数，那么这两个堆，大顶堆用来存较小的数，从大到小排列；(注意一定要分奇偶数)
    小顶堆存较大的数，从小到大的顺序排序*，显然中位数就是大顶堆的根节点与小顶堆的根节点和的平均数。
⭐保证：小顶堆中的元素都大于等于大顶堆中的元素，所以每次塞值，并不是直接塞进去，而是从另一个堆中poll出一个最大（最小）的塞值
⭐当数目为偶数的时候，将这个值插入大顶堆中，再将大顶堆中根节点（即最大值）插入到小顶堆中；
⭐当数目为奇数的时候，将这个值插入小顶堆中，再讲小顶堆中根节点（即最小值）插入到大顶堆中；
⭐取中位数的时候，如果当前个数为偶数，显然是取小顶堆和大顶堆根结点的平均值；如果当前个数为奇数，显然是取小顶堆的根节点

 * author: lcxanhui@163.com
 * time: 2019.7.8
 ******************************************************************************************************/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
	void Insert(int num)
	{
		if (max_heap.size() == 0)
		{
			max_heap.push(num);
			return;
		}
		//下面分三大种情况进行讨论，每种情况有特殊的小情况
		if (max_heap.size() == min_heap.size())
		{
			if (num < max_heap.top())
				max_heap.push(num);
			else
				min_heap.push(num);
		}
		else if (max_heap.size() > min_heap.size()) //此种情况下下一个数据应该插入到小顶堆中
		{ //注意特殊情况，也就是插入小顶堆的数比大顶堆的堆顶的数还要小
			if (num < max_heap.top())
			{
				min_heap.push(max_heap.top());
				max_heap.pop();
				max_heap.push(num);
			}
			else
				min_heap.push(num);
		}
		else if (max_heap.size() < min_heap.size())  //此种情况下下一个数据应该插入到大顶堆中
		{
			if (num > min_heap.top())
			{
				max_heap.push(min_heap.top());
				min_heap.pop();
				min_heap.push(num);
			}
			else
				max_heap.push(num);
		}
	}

	double GetMedian()
	{
		if (max_heap.size() == min_heap.size())
			return (max_heap.top() + min_heap.top()) / 2.0;
		else if (max_heap.size() > min_heap.size())
			return max_heap.top();
		else
			return min_heap.top();
	}
private:
	priority_queue<int, vector<int>, less<int>()> max_heap;   //最大堆（大顶堆）--系统默认
	priority_queue<int, vector<int>, greater<int>()> min_heap;    //最小堆（小顶堆）
};
int main(void)
{
	Solution s;
	s.Insert(5);
	cout << s.GetMedian() << " ";
	s.Insert(2);
	cout << s.GetMedian() << " ";
	s.Insert(6);
	cout << s.GetMedian() << " ";
	s.Insert(4);
	cout << s.GetMedian() << " ";
	system("pause");
	return 0;
}