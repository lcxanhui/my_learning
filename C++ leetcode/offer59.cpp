/*****************************************************************************************************
 *                    剑指offer第59题
 * 请实现一个函数，用来判断一颗二叉树是不是对称的。注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
 *
 * Input:  二叉树
 * Output: 二叉树是否是对称的
 *
 * Note:(本题分为递归和非递归的做法，重点掌握非递归的做法)
 * 思路都是相同的：用前序遍历的经典做法来进行
   从上到下递归遍历，比较左右两棵子树，分别错位比较，
   即左子树的左节点与右子树的右节点比较，左子树的右节点与右子树的左节点比较

 * author: lcxanhui@163.com
 * time: 2019.7.6
 ******************************************************************************************************/

#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

#define MAX 12

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	struct TreeNode *next;
	//TreeNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
	//}
};
//创建树
void CreateTree(TreeNode **root, int n)
{
	if (n <= 0)
		return;
	TreeNode* arr[MAX];

	for (int i = 0; i < n; i++)
	{
		arr[i] = new TreeNode;
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
void DeleteTree(TreeNode **root)
{
	if ((*root) == NULL)
		return;
	DeleteTree(&((*root)->left));
	DeleteTree(&((*root)->right));
	delete *root;
}
//递归做法，比较简单
//bool isSame(TreeNode *p1, TreeNode *p2)
//{
//	if (p1 == NULL && p2 == NULL)
//		return true;
//	if (p1 != NULL && p2 == NULL)
//		return false;
//	if (p1 == NULL && p2 != NULL)
//		return false;
//	if (p1->val == p2->val)
//		return isSame(p1->left, p2->right) && isSame(p1->right, p2->left);
//	return false;
//}
//
//bool isSymmetrical(TreeNode *root)
//{
//	if (root == NULL)
//		return true;
//	return isSame(root->left, root->right);
//}



//非递归做法，需要用到stack，每次非递归对树结构操作，都要用到stack结构，需要熟练掌握
bool isSymmetrical(TreeNode *root)
{
	if (root == NULL)
		return true;
	stack<TreeNode*> s1, s2;
	TreeNode *p1, *p2;
	p1 = p2 = root;
	while ((!s1.empty() && !s2.empty()) || (p1 != NULL && p2 != NULL))
	{
		while (p1 != NULL && p2 != NULL)
		{
			s1.push(p1);
			s2.push(p2);
			p1 = p1->left;
			p2 = p2->right;
		}
		if(!s1.empty() && !s2.empty())
		{
			p1 = s1.top();
			p2 = s2.top();
			s1.pop();
			s2.pop();
			if (p1->val != p2->val)
				return false;
			p1 = p1->right;
			p2 = p2->left;
		}
	}
	if (!s1.empty() || !s2.empty())
		return false;
	if(p1 != NULL || p2 != NULL)
		return false;
	return true;
}

int main(void)
{
	int n;
	while (cin >> n)
	{
		TreeNode *root = NULL;
		CreateTree(&root, n);
		bool res=isSymmetrical(root);
		DeleteTree(&root);
	}

	return 0;
}
