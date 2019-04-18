/*****************************************************************************************************
 *         ��ָoffer��7��
 * ������ջ��ʵ��һ�����У���ɶ��е�Push��Pop������ �����е�Ԫ��Ϊint���͡�
 *
 * Input:  
 * Output: 
 *
 * Note: 
 * ջ�������Ǻ���ȳ��������е�˼�����Ƚ��ȳ���Ҫ����ջʵ�ֶ��У�����빹������ջ��ͨ����s1��ջ������
   ѹջ��s2���ٽ�s2�����ݵ�������ʵ�ֶ��С��жϷ�ʽ��
		��1�����s2��Ϊ�գ��򷵻ض������ݼ���
        ��2�����s2Ϊ�գ�s1��Ϊ�գ���s1���ݸ��Ƶ�s2�У�������s2����
        ��3�����s1Ϊ�գ����׳��쳣
 *****���������Ż��Ŀ����ԣ�����˵stack1ѹջ��stack2��ʱ�����Բ���ѹջstack1��ջ�ף��������ܼ���һ��
      ѹջ�����������  https://www.cnblogs.com/wanghui9072229/archive/2011/11/22/2259391.html
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
		cout << "������PUSH��POP ";
		cin >> cmds;
		if (cmds == "PUSH")
		{
			cin >> num;
			push(stack1, num);
		}
		if (cmds == "POP")
		{
			num = pop(stack1, stack2);
			cout << "ջ������Ϊ" << num << endl;
		}
	}
	system("pause");
	return 0;
}