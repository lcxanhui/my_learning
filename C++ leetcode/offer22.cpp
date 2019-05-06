/*****************************************************************************************************
 *         ��ָoffer��22��
 * ���������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ����Ϊ��ջ�ĵ���˳�򡣼���ѹ��ջ
   ���������־�����ȡ���������1,2,3,4,5��ĳջ��ѹ��˳������4,5,3,2,1�Ǹ�ѹջ���ж�Ӧ��һ���������У�
   ��4,3,5,1,2�Ͳ������Ǹ�ѹջ���еĵ������С���ע�⣺���������еĳ�������ȵģ�
 *
 * Input:   ����ջ����
 * Output:  0��1
 *
 * Note:
 *  ģ���ջ��������ԭ��������ѹջ��ջ��Ԫ����������ջ������ȣ������ͬ���ջ��
    �����ͬ�����ѹջ��ֱ��ԭ��������������ѹջ��ϡ�
    ���ջ���Ƿ�Ϊ�գ����գ�˵����ջ���п���ԭ���н���ջ�����õ�������˵����ջ���в�����ԭ���н���ջ�����õ���
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
		while (j < popV.size() && !res.empty() && res.back() == popV[j])  //�ж�ջ��Ԫ����������ջ���У���ͬ��ջ����ͬ����ѹջ
		{
			res.pop_back();      //back()Ϊջ����Ԫ�أ�pop_back()Ϊ����ջ����Ԫ�ز�ɾ��
			j++;
		}
	}
	return res.empty();
}

int main(void)
{
	// ��������1��2��3��4��5��4��5��3��2��1
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