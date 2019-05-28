/*****************************************************************************************************
 *         剑指offer第41-2题
 * 题目描述
 * 小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。但是他并不满足
   于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。没多久,他就得到另一组连续正数和为100
   的序列:18,19,20,21,22。现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列? 
 *
 * Input:  和sum
 * Output: 和为sum的数组序列
 *
 * Note: （滑窗法）
 *  就是相当于有一个窗口，窗口的左右两边就是两个指针，我们根据窗口内值之和来确定窗口的位置和宽度。
 
 * author: lcxanhui@163.com
 * time: 2019.5.28
 ******************************************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > FindContinuousSequence(int sum)
{
	vector<vector<int> > resAll;
	if (sum <= 0)
		return resAll;
	//两个起点，相当于动态窗口的两边，根据其窗口内的值的和来确定窗口的位置和大小
	int low = 1, high = 2;
	while (low < high)
	{
		//由于是连续的，差为1的一个序列，那么求和公式是(a0+an)*n/2
		int cur = (low + high)*(high - low + 1) >> 1;
		//相等，那么就将窗口范围的所有数添加进结果集
		if (cur == sum)
		{
			vector<int> res;
			for (int i = low; i <= high; i++)
				res.push_back(i);
			resAll.push_back(res);
			low++;
		}
		//如果当前窗口内的值之和小于sum，那么右边窗口右移一下
		else if (cur < sum)
			high++;
		//如果当前窗口内的值之和大于sum，那么左边窗口右移一下
		else if (cur > sum)
			low++;
	}
	return resAll;
}

int main(void) {
	int sum = 15;
	vector<vector<int> > resAll = FindContinuousSequence(sum);
	for (int i = 0; i < resAll.size(); i++) {
		for (int j = 0; j < resAll[0].size(); j++)
		{
			cout << resAll[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}