/*****************************************************************************************************
 *         剑指offer第58题
 * 给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。注意，树中的结点不仅包含左右
   子结点，同时包含指向父结点的指针。
 *
 * Input:  中序遍历的二叉树
 * Output: 二叉树某一节点的下一节点
 *
 * Note:
 * 分析二叉树的下一个节点，一共有以下情况：
  1.二叉树为空，则返回空；
  2.节点右孩子存在，则设置一个指针从该节点的右孩子出发，一直沿着指向左子结点的指针找到的叶子节点即为下一个节点；
  3.节点不是根节点。 
     如果该节点是其父节点的左孩子，则返回父节点；
	 否则继续向上遍历其父节点的父节点，重复之前的判断，返回结果。

 * author: lcxanhui@163.com
 * time: 2019.7.5
 ******************************************************************************************************/

#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

#define MAX 12

struct TreeLinkNode {
	int val;
	struct TreeLinkNode *left;
	struct TreeLinkNode *right;
	struct TreeLinkNode *next;
	//TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
	//}
};
//创建树
void CreateTree(TreeLinkNode **root, int n)
{
	if (n <= 0)
		return;
	TreeLinkNode* arr[MAX];

	for (int i = 0; i < n; i++)
	{
		arr[i] = new TreeLinkNode;
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
void DeleteTree(TreeLinkNode **root)
{
	if ((*root) == NULL)
		return;
	DeleteTree(&((*root)->left));
	DeleteTree(&((*root)->right));
	delete *root;
}


TreeLinkNode* GetNext(TreeLinkNode *root)
{
	if (root == NULL)
		return NULL;
	//该节点有右子树的情况下，找到其右子树的最左的节点
	if (root->right != NULL)
	{
		root=root->right;
		while (root->left != NULL)
			root = root->left;
		return root;
	}
	//没有右子树的情况下分为两种情况讨论
	else
	{
		while (root->next != NULL)  //防止为根节点的情况
		{
			TreeLinkNode* proot = root->next;
			if (proot->left == root)//左子孩切没有右子树
				return proot;
			root = root->next;  //继续遍历，右子孩并且没有右子树直接指向父节点
		}
	}
	return NULL;
}

int main(void)
{
	int n;
	while (cin >> n)
	{
		TreeLinkNode *root = NULL;
		CreateTree(&root, n);
		GetNext(root);
		DeleteTree(&root);
	}

	return 0;
}