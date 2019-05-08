/*****************************************************************************************************
 *         ��ָoffer��27��
 * ����һ�ö��������������ö���������ת����һ�������˫������Ҫ���ܴ����κ��µĽ�㣬ֻ�ܵ���
   ���н��ָ���ָ��
 *
 * Input:  ������
 * Output: ˫������
 *
 * Note:�������������������˫������֮���ת����
 *
	1.�������������˫��������������ͷ�ڵ㡣
	2.��λ��������˫�������һ���ڵ㡣
	3.�������������Ϊ�յĻ�������ǰroot׷�ӵ�����������
	4.�������������˫��������������ͷ�ڵ㡣
	5.�������������Ϊ�յĻ�����������׷�ӵ�root�ڵ�֮��
	6.���������������Ƿ�Ϊ��ȷ�����صĽڵ㡣
 
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
	//�������������������������ʱ���������������ֱ�ָ���һ��Ԫ��
	TreeNode* leftsub = TreeToList(root->left);
	TreeNode* rightsub = TreeToList(root->right);
	//ָ���������ĵ�һ��Ԫ�أ�����Ҫ���������������һ��Ԫ���Ա�����ڵ�����
	TreeNode* tmp=leftsub;
	while (tmp != NULL)
	{
		//������������ֱ������
		if (tmp->right != NULL)
			tmp = tmp->right;
		//�����������һ������ڵ�����
		tmp->right = root;
	}
	//���ڵ�����ҷֱ�����Ϊ�����������һ�����������ĵ�һ��
	root->left = tmp;
	root->right = rightsub;
	//���������ĵ�һ������ڵ����ӣ�˫������
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