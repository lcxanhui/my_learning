/*****************************************************************************************************
 *         剑指offer第24题
 * 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设
   输入的数组的任意两个数字都互不相同。
 *
 * Input:  序列vector<int> num
 * Output: 0或1
 *
 * Note:（后序遍历BTS的特征：后序遍历的最后一个元素为根节点，左子树的元素均小于根节点，右子树的元素均大于根节点）
 *  1、确定root=seq[len-1]；
	2、遍历序列（除去root结点），找到第一个大于root的位置，则该位置左边为左子树，右边为右子树；
	3、遍历右子树，若发现有小于root的值，则直接返回false；
	4、分别判断左子树和右子树是否仍是二叉搜索树（即递归步骤1、2、3）

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
	int root = sequence[len - 1];       //根节点为后序遍历的最后一个参数
	vector<int> leftTree, rightTree;    //左子树和右子树为后续的递归初始化
	int i=0;
	for (; i < len - 1; i++)
	{
		if (sequence[i] > root)        //查找左右子树的分界点，左子树均小于根节点，右子树均大于根节点
			break;
	}
	for (int j = i; j < len - 1; j++)
	{
		if (sequence[j] < root)       //如果右子树的某一元素大于根节点，则次二叉树序列非后序遍历序列
			return false;
	}
	if (i != 0)
	{
		for (int k = 0; k < i; k++)
			leftTree.push_back(sequence[k]);    //构建左子树，其中分界点为上面保存的i
	}
	if (i != len-2)
	{
		for (int j = i; j < len-1; j++)
			rightTree.push_back(sequence[j]);   //构建右子树，右子树为i到len-2的所有参数
	}
	bool leftSub = true, rightSub = true;
	if (leftTree.size() > 1)
		VerifySequenceOfBTS(leftTree);        //左右子树的递归判断
	if (rightTree.size() > 1)
		VerifySequenceOfBTS(rightTree);
	return (leftSub&&rightSub);
}

int main()
{
	vector<int> arr;  
	//初始化，测试用例{5，7，6，9，11，10，8}和{7，4，5，6}
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