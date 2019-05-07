/*****************************************************************************************************
 *         ��ָoffer��24��
 * ����һ���������飬�жϸ������ǲ���ĳ�����������ĺ�������Ľ��������������Yes,�������No������
   ���������������������ֶ�������ͬ��
 *
 * Input:  ����vector<int> num
 * Output: 0��1
 *
 * Note:���������BTS��������������������һ��Ԫ��Ϊ���ڵ㣬��������Ԫ�ؾ�С�ڸ��ڵ㣬��������Ԫ�ؾ����ڸ��ڵ㣩
 *  1��ȷ��root=seq[len-1]��
	2���������У���ȥroot��㣩���ҵ���һ������root��λ�ã����λ�����Ϊ���������ұ�Ϊ��������
	3����������������������С��root��ֵ����ֱ�ӷ���false��
	4���ֱ��ж����������������Ƿ����Ƕ��������������ݹ鲽��1��2��3��

 * author: lcxanhui@163.com
 * time: 2019.5.7
 ******************************************************************************************************/

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

bool VerifySequenceOfBTS(vector<int> sequence)
{
	int len= sequence.size();
	if (len == 0)
		return false;
	int root = sequence[len - 1];       //���ڵ�Ϊ������������һ������
	vector<int> leftTree, rightTree;    //��������������Ϊ�����ĵݹ��ʼ��
	int i=0;
	for (; i < len - 1; i++)
	{
		if (sequence[i] > root)        //�������������ķֽ�㣬��������С�ڸ��ڵ㣬�����������ڸ��ڵ�
			break;
	}
	for (int j = i; j < len - 1; j++)
	{
		if (sequence[j] < root)       //�����������ĳһԪ�ش��ڸ��ڵ㣬��ζ��������зǺ����������
			return false;
	}
	if (i != 0)
	{
		for (int k = 0; k < i; k++)
			leftTree.push_back(sequence[k]);    //���������������зֽ��Ϊ���汣���i
	}
	if (i != len-2)
	{
		for (int j = i; j < len-1; j++)
			rightTree.push_back(sequence[j]);   //������������������Ϊi��len-2�����в���
	}
	bool leftSub = true, rightSub = true;
	if (leftTree.size() > 1)
		VerifySequenceOfBTS(leftTree);        //���������ĵݹ��ж�
	if (rightTree.size() > 1)
		VerifySequenceOfBTS(rightTree);
	return (leftSub&&rightSub);
}

int main()
{
	vector<int> arr;  
	//��ʼ������������{5��7��6��9��11��10��8}��{7��4��5��6}
	arr.push_back(7);
	arr.push_back(4);
	arr.push_back(5);
	arr.push_back(6);
	//arr.push_back(5);
	//arr.push_back(7);
	//arr.push_back(6);
	//arr.push_back(9);
	//arr.push_back(11);
	//arr.push_back(10);
	//arr.push_back(8);
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	bool result=true;
	result= VerifySequenceOfBTS(arr);
	return result;
}