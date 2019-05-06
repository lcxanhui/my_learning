/*****************************************************************************************************
 *         剑指offer第22题
 * 输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。假设压入栈
   的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，
   但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）
 *
 * Input:   两个栈序列
 * Output:  0或1
 *
 * Note:
 *  模拟堆栈操作：将原数列依次压栈，栈顶元素与所给出栈队列相比，如果相同则出栈，
    如果不同则继续压栈，直到原数列中所有数字压栈完毕。
    检测栈中是否为空，若空，说明出栈队列可由原数列进行栈操作得到。否则，说明出栈队列不能由原数列进行栈操作得到。
 * author: lcxanhui@163.com
 * time: 2019.5.6
 ******************************************************************************************************/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool isPopInorder(vector<int> pushV, vector<int> popV)
{
	if (pushV.empty() || popV.empty() || pushV.size() != popV.size())
		return false;
	vector<int> res;
	for (int i = 0, j = 0; i < pushV.size(); i++)
	{
		res.push_back(pushV[i]);   
		while (j < popV.size() && !res.empty() && res.back() == popV[j])  //判断栈顶元素与所给出栈队列，相同出栈，不同继续压栈
		{
			res.pop_back();      //back()为栈顶的元素，pop_back()为弹出栈顶的元素并删除
			j++;
		}
	}
	return res.empty();
}

int main(void)
{
	// 测试用例1，2，3，4，5和4，5，3，2，1
	vector<int> pushV;
	vector<int> popV;
	pushV.push_back(1);
	pushV.push_back(2); 
	pushV.push_back(3); 
	pushV.push_back(4);
	pushV.push_back(5);
	for (int i = 0; i < pushV.size(); i++)
		cout << pushV[i] << " ";
	popV.push_back(4);
	popV.push_back(5);
	popV.push_back(3);
	popV.push_back(1);
	popV.push_back(2);
	bool result = false;
	result = isPopInorder(pushV, popV);
	return result;
}