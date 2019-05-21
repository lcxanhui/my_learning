/*****************************************************************************************************
 *         剑指offer第39题
 * 输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长
   路径的长度为树的深度。
 *
 * Input:  二叉树
 * Output: 二叉树的深度（int）
 *
 * Note:（递归和非递归，重点掌握非递归）
 * a.递归算法很简单，但是注意最后要考虑根节点的问题，结果要+1；
   b.非递归算法即循环实现利用队列
   1.建立存储树节点指针的队列；
   2.将根节点压入队列；
   3.利用两层循环，第一层循环，记录第几层（即所求，深度）；第二层循环完成将一层从队列中取出和下一层的
     节点的压入

 * author: lcxanhui@163.com
 * time: 2019.5.21
 ******************************************************************************************************/

#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

#define MAX 12

struct BinaryTree
{
	BinaryTree *left;
	BinaryTree *right;
};
//创建树
void CreateTree(BinaryTree **root, int n)
{
	if (n <= 0)
		return;
	BinaryTree* arr[MAX];

	for (int i = 0; i < n; i++)
	{
		arr[i] = new BinaryTree;
		arr[i]->left = NULL;
		arr[i]->right = NULL;
	}
	int left, right;
	for (int i = 0; i < n; i++)
	{
		cin >> left >> right;
		if (left != -1)
			arr[i]->left = arr[left - 1];
		if (right != -1)
			arr[i]->right = arr[right - 1];
	}
	*root = arr[0];
}
//删除树
void DeleteTree(BinaryTree **root)
{
	if ((*root) == NULL)
		return;
	DeleteTree(&((*root)->left));
	DeleteTree(&((*root)->right));
	delete *root;
}


int MaxDepth(BinaryTree *root)
{
//********************递归算法****************
	//if (root == NULL)
	//	return 0;
	//int left = MaxDepth(root->left);
	//int right = MaxDepth(root->right);
	//return (left >= right) ? left + 1 : right + 1;   //注意此处要加1，为根节点
//********************非递归算法（重点掌握）***************
	if (root == NULL)
		return 0;
	queue<BinaryTree*> q;   //利用队列实现
	q.push(root);
	int depth = 0;       //初始化深度
	while (!q.empty())
	{
		depth++;
		int size = q.size();
		for (int i = 0; i < size; i++)
		{
			root = q.front();
			if (root->left)
				q.push(root->left);
			if (root->right)
				q.push(root->right);
			q.pop();
		}
	}
	return depth;
}

int main(void)
{
	int n;
	while (cin >> n)
	{
		BinaryTree *root = NULL;
		CreateTree(&root, n);
		int depth = MaxDepth(root);
		cout << depth << endl;
		DeleteTree(&root);
	}

	return 0;
}