/*****************************************************************************************************
 *                     剑指offer第65题
 * 给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。例如，如果输入数组{2,3,4,2,6,2,5,1}及
 滑动窗口的大小3，那么一共存在6个滑动窗口，他们的最大值分别为{4,4,6,6,6,5}； 针对数组{2,3,4,2,6,2,5,1}
 的滑动窗口有以下6个： {[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}， {2,3,4,[2,6,2],5,1}，
 {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。
 *
 * Input:  数组以及滑动窗口的大小
 * Output: 数组中滑窗中的最大值
 *
 * Note: （利用队列存放最大值得下标，根据滑窗获取最大值）
 * 具体分析见下面的代码，要求掌握

 * author: lcxanhui@163.com
 * time: 2019.7.14
 ******************************************************************************************************/


#include<iostream>
#include<vector>
#include<deque>
using namespace std;

class Solution {
public:
	vector<int> MaxInWindows(vector<int> &num, unsigned int size)
	{
		vector<int> res;   //保存最后结果
		if (num.empty() || size < 1)
			return res;
		deque<int> s;      //两端队列保存最大值所在的下标
		for (int i = 0; i < num.size(); i++)
		{
			//队列非空并且从后面依次弹出队列中比当前num值小的元素，同时也能保证队列首元素为当前窗口最大值下标
			while (!s.empty() && num[s.back()] <= num[i])
				s.pop_back();
			//当当前窗口移出队首元素所在的位置，即队首元素坐标对应的num不在窗口中，需要弹出
			while (!s.empty() && i - s.front() + 1 > size)
				s.pop_front();
			s.push_back(i);    //把每次滑动的num下标加入队列
			if (size != 0 && (i + 1) >= size)      //当滑动窗口首地址i大于等于size时才开始写入窗口最大值
				res.push_back(num[s.front()]);
		}
		return res;
	}
};

int main()
{
	vector<int> num{ 2,3,4,2,6,2,5,1 };
	vector<int> res;
	Solution s;
	res = s.MaxInWindows(num, 3);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	cout << endl;
	system("pause");
	return 0;
}