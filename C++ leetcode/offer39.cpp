/*****************************************************************************************************
 *         ��ָoffer��39��
 * ����һ�ö����������������ȡ��Ӹ���㵽Ҷ������ξ����Ľ�㣨������Ҷ��㣩�γ�����һ��·�����
   ·���ĳ���Ϊ������ȡ�
 *
 * Input:  ������
 * Output: ����������ȣ�int��
 *
 * Note:���ݹ�ͷǵݹ飬�ص����շǵݹ飩
 * a.�ݹ��㷨�ܼ򵥣�����ע�����Ҫ���Ǹ��ڵ�����⣬���Ҫ+1��
   b.�ǵݹ��㷨��ѭ��ʵ�����ö���
   1.�����洢���ڵ�ָ��Ķ��У�
   2.�����ڵ�ѹ����У�
   3.��������ѭ������һ��ѭ������¼�ڼ��㣨��������ȣ����ڶ���ѭ����ɽ�һ��Ӷ�����ȡ������һ���
     �ڵ��ѹ��

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
//������
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
//ɾ����
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
//********************�ݹ��㷨****************
	//if (root == NULL)
	//	return 0;
	//int left = MaxDepth(root->left);
	//int right = MaxDepth(root->right);
	//return (left >= right) ? left + 1 : right + 1;   //ע��˴�Ҫ��1��Ϊ���ڵ�
//********************�ǵݹ��㷨���ص����գ�***************
	if (root == NULL)
		return 0;
	queue<BinaryTree*> q;   //���ö���ʵ��
	q.push(root);
	int depth = 0;       //��ʼ�����
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