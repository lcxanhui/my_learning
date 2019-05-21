/*****************************************************************************************************
 *         剑指offer第39-2题
 * 输入一棵二叉树，判断该二叉树是否是平衡二叉树。
 *
 * Input:  二叉树
 * Output: 二叉树是否为平衡数
 *
 * Note:（递归和非递归，重点掌握非递归）
 * 利用39题二叉树的深度的基础上，获取到左右子树的深度，
   如果左右子树的深度差值的绝对值大于1，则为false, 否则继续递归左右子树

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
		if (root == NULL)
			return 0;
		int left = MaxDepth(root->left);
		int right = MaxDepth(root->right);
		return (left >= right) ? left + 1 : right + 1;   //注意此处要加1，为根节点
}

bool isBalancedTree(BinaryTree *root)
{
	if (root == NULL)
		return true;
	int leftsub = MaxDepth(root->left);     //获得左子树和右子树的高度
	int rightsub = MaxDepth(root->right);
	if (abs(leftsub - rightsub) > 1)       //左右子树的高度大于1，则不是平衡树，接下递归左子树和右子树
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