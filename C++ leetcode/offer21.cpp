/*****************************************************************************************************
 *         剑指offer第21题
 * 定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。
 *
 * Input:  数据栈
 * Output: 数据栈的最小元素
 *
 * Note: （结合例子分析比较直观）
 * 应用一个***辅助栈***，压的时候，如果A栈的压入比B栈压入大，B栈不压，，，，小于等于，AB栈同时压入，
                   出栈，如果，AB栈顶元素不等，A出，B不出。
 * author: lcxanhui@163.com
 * time: 2019.5.5
 ******************************************************************************************************/

#include <iostream>
#include <stack>

using namespace std;

template <typename T>
class StackWithMin {
public:
	void push(const T& value);
	void pop();
	const T& top() const;
	const T& min() const;
private:
	typename stack<T> stack1;
	typename stack<T> stack2;      // 辅助栈，该辅助栈的栈顶一直保存压栈后的最小元素
};

template <typename T> void StackWithMin<T>::push(const T& value) {
	stack1.push(value);
	if (stack2.empty() || value < stack2.top())
		stack2.push(value);
	else
		stack2.push(stack2.top());
}

template <typename T> void StackWithMin<T>::pop() {
	if (!stack1.empty() && !stack2.empty())
	{
		stack2.pop();
		stack1.pop();
	}
}

template <typename T> const T& StackWithMin<T>::top() const {
	if (!stack1.empty() && !stack2.empty()) {
		return stack1.top();
	}
}

template <typename T> const T& StackWithMin<T>::min() const {
	if (!stack1.empty() && !stack2.empty()) {
		return stack2.top();
	}
}

int main(void)
{
	StackWithMin<int> min_stack;
	min_stack.push(3);
	min_stack.push(4);
	min_stack.push(2);
	min_stack.push(1);
	cout << min_stack.min();
	min_stack.pop();
	cout << min_stack.min();
	cout << min_stack.top();
	return 0;
}