/*****************************************************************************************************
 *         ��ָoffer��21��
 * ����ջ�����ݽṹ�����ڸ�������ʵ��һ���ܹ��õ�ջ��������СԪ�ص�min������ʱ�临�Ӷ�ӦΪO��1������
 *
 * Input:  ����ջ
 * Output: ����ջ����СԪ��
 *
 * Note: ��������ӷ����Ƚ�ֱ�ۣ�
 * Ӧ��һ��***����ջ***��ѹ��ʱ�����Aջ��ѹ���Bջѹ���Bջ��ѹ��������С�ڵ��ڣ�ABջͬʱѹ�룬
                   ��ջ�������ABջ��Ԫ�ز��ȣ�A����B������
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
	typename stack<T> stack2;      // ����ջ���ø���ջ��ջ��һֱ����ѹջ�����СԪ��
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