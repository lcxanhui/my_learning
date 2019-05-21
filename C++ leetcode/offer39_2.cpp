/*****************************************************************************************************
 *         ��ָoffer��39-2��
 * ����һ�ö��������жϸö������Ƿ���ƽ���������
 *
 * Input:  ������
 * Output: �������Ƿ�Ϊƽ����
 *
 * Note:���ݹ�ͷǵݹ飬�ص����շǵݹ飩
 * ����39�����������ȵĻ����ϣ���ȡ��������������ȣ�
   ���������������Ȳ�ֵ�ľ���ֵ����1����Ϊfalse, ��������ݹ���������

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
		if (root == NULL)
			return 0;
		int left = MaxDepth(root->left);
		int right = MaxDepth(root->right);
		return (left >= right) ? left + 1 : right + 1;   //ע��˴�Ҫ��1��Ϊ���ڵ�
}

bool isBalancedTree(BinaryTree *root)
{
	if (root == NULL)
		return true;
	int leftsub = MaxDepth(root->left);     //������������������ĸ߶�
	int rightsub = MaxDepth(root->right);
	if (abs(leftsub - rightsub) > 1)       //���������ĸ߶ȴ���1������ƽ���������µݹ���������������
		return false;
	return (isBalancedTree(root->left) && isBalancedTree(root->right));

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