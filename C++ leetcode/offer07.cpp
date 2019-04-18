/*****************************************************************************************************
 *         剑指offer第7题
 * 用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
 *
 * Input:  
 * Output: 
 *
 * Note: 
 * 栈的特性是后进先出，而队列的思想是先进先出，要想用栈实现队列，则必须构建两个栈，通过将s1的栈的内容
   压栈到s2，再将s2的数据弹出即可实现队列。判断方式：
		（1）如果s2不为空，则返回顶部数据即可
        （2）如果s2为空，s1不为空，则s1数据复制到s2中，并返回s2数据
        （3）如果s1为空，则抛出异常
 *****本程序还有优化的可能性，比如说stack1压栈到stack2中时，可以不用压栈stack1的栈底，这样就能减少一次
      压栈操作，具体见  https://www.cnblogs.com/wanghui9072229/archive/2011/11/22/2259391.html
 * authur: lcxanhui@163.com
 * time: 2019.4.18
 ******************************************************************************************************/

#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

int push(stack<int> &stack1, int num)
{
	stack1.push(num);
	return 0;
}

int pop(stack<int> &stack1, stack<int> &stack2)
{
	int num;
	if (!stack2.empty())
	{
		num = stack2.top();
		stack2.pop();
		return num;
	}
	if (stack1.empty())
		return -1;
	while (!stack1.empty())
	{
		num = stack1.top();
		stack2.push(num);
		stack1.pop();
	}
	stack2.pop();
	return num;
}

int main(void)
{
	int n, num;
	string cmds;
	stack<int> stack1;
	stack<int> stack2;
	cin >> n;
	while (n--)
	{
		cout << "请输入PUSH或POP ";
		cin >> cmds;
		if (cmds == "PUSH")
		{
			cin >> num;
			push(stack1, num);
		}
		if (cmds == "POP")
		{
			num = pop(stack1, stack2);
			cout << "栈顶的数为" << num << endl;
		}
	}
	system("pause");
	return 0;
}