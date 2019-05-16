/*****************************************************************************************************
 *         剑指offer第27题
 * 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整
   树中结点指针的指向。
 *
 * Input:  二叉树
 * Output: 双向链表
 *
 * Note:（二叉树的中序遍历与双向链表之间的转化）
 *
	1.将左子树构造成双链表，并返回链表头节点。
	2.定位至左子树双链表最后一个节点。
	3.如果左子树链表不为空的话，将当前root追加到左子树链表。
	4.将右子树构造成双链表，并返回链表头节点。
	5.如果右子树链表不为空的话，将该链表追加到root节点之后。
	6.根据左子树链表是否为空确定返回的节点。
 
 * author: lcxanhui@163.com
 * time: 2019.5.8
 ******************************************************************************************************/

#include <iostream>
#include <cstdio>

using namespace std;

struct TreeNode
{
	int value;
	TreeNode *left;
	TreeNode *right;
};


void CreateTree(TreeNode ** root)
{
	//TreeNode *index;
	int value;
	cin >> value;
	if (value != 0)
	{
		(*root) = new TreeNode;
		(*root)->value = value;
		(*root)->left = NULL;
		(*root)->right = NULL;
		CreateTree(&(*root)->left);
		CreateTree(&((*root)->right));

	}

}

TreeNode* TreeToList(TreeNode *root)
{
	if (root == NULL)
		return NULL;
	if (root->left == NULL && root->right == NULL)
		return root;
	//将左右子树进行中序遍历，此时左子树和右子树分别指向第一个元素
	TreeNode* leftsub = TreeToList(root->left);
	TreeNode* rightsub = TreeToList(root->right);
	//指向左子树的第一个元素，下面要遍历左子树到最后一个元素以便与根节点连接
	TreeNode* tmp=leftsub;
	while (tmp != NULL)
	{
		//遍历左子树，直至结束
		if (tmp->right != NULL)
			tmp = tmp->right;
		//左子树的最后一个与根节点连接
		tmp->right = root;
	}
	//根节点的左右分别设置为左子树的最后一个和右子树的第一个
	root->left = tmp;
	root->right = rightsub;
	//将右子树的第一个与根节点连接（双向链表）
	if (rightsub != NULL)
		rightsub->left = root;

	TreeNode* res = root;
	while (res->left != NULL)
		res = res->left;
	return res;
}

void DeleteTree(TreeNode **root)
{
	if ((*root) == NULL)
		return;
	TreeNode *index = *root;
	TreeNode *tmp = index;
	while (index)
	{
		tmp = index;
		index = index->right;
		delete (tmp);
	}
}

void PrintList(TreeNode *head)
{
	if (head == NULL)
		return;
	TreeNode *index = head;
	while (index)
	{
		cout << index->value << " ";
		index = index->right;
	}

}


int main(void)
{
	int n;
	cin >> n;
	while (n--)
	{
		TreeNode *root = NULL;
		CreateTree(&root);
		TreeNode* res;
		res = TreeToList(root);
		PrintList(res);
		cout << endl;
		DeleteTree(&root);

	}

	return 0;
}
