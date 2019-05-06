/*****************************************************************************************************
 *         ��ָoffer��23��
 * �������´�ӡ����������ÿ���ڵ㣬ͬ��ڵ�������Ҵ�ӡ��
 *
 * Input:   ������
 * Output:  �������Ĺ�����ȱ�������
 *
 * Note:
 *  ���ø�������ʵ�ֹ�����ȱ�����������������������ͼ���ö���ʵ�֣�
    1.����ʼ��ŵ������У�
	2.������ÿһ�δӶ��е�ͷ��ȡ��һ���ڵ㣬��������ڵ�֮��Ѵ����ܵ���Ľڵ㶼һ�ηŵ�����
	3.�ظ��������̣�ֱ�������еĽڵ�ȫ��������Ϊֹ
 * author: lcxanhui@163.com
 * time: 2019.5.6
 ******************************************************************************************************/

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

struct TreeNode
{
	int value;
	TreeNode *left;
	TreeNode *right;
};

int num;

void CreateTree(TreeNode **root, int n)
{
	int *num = new int[n], i, tmp;
	char child_num;
	TreeNode *index, *tmpNode;
	queue<TreeNode *> Bqueue;
	if (n <= 0)
	{
		*root = NULL;
		return;
	}
	*root = new TreeNode;
	(*root)->left = NULL;
	(*root)->right = NULL;

	for (i = 0; i < n; i++)
		cin >> num[i];
	(*root)->value = num[0];
	Bqueue.push(*root);
	for (i = 0; i < n; i++)
	{
		cin >> child_num;
		index = Bqueue.front();
		Bqueue.pop();
		if (child_num == 'd')
		{
			cin >> tmp;
			tmpNode = new TreeNode;
			tmpNode->value = num[tmp - 1];
			tmpNode->left = NULL;
			tmpNode->right = NULL;
			index->left = tmpNode;
			Bqueue.push(tmpNode);
			cin >> tmp;
			tmpNode = new TreeNode;
			tmpNode->value = num[tmp - 1];
			tmpNode->left = NULL;
			tmpNode->right = NULL;
			index->right = tmpNode;
			Bqueue.push(tmpNode);
		}
		else if (child_num == 'l')
		{
			cin >> tmp;
			tmpNode = new TreeNode;
			tmpNode->value = num[tmp - 1];
			tmpNode->left = NULL;
			tmpNode->right = NULL;
			index->left = tmpNode;
			Bqueue.push(tmpNode);
		}
		else if (child_num == 'r')
		{
			cin >> tmp;
			tmpNode = new TreeNode;
			tmpNode->value = num[tmp - 1];
			tmpNode->right = NULL;
			tmpNode->left = NULL;
			index->right = tmpNode;
			Bqueue.push(tmpNode);
		}
		if (child_num == 'z')
		{
			continue;
		}
	}

	delete num;
	return;
}

int DeleteTree(TreeNode **root)
{
	if (*root == NULL)
		return 0;
	if ((*root)->left != NULL)
		DeleteTree(&((*root)->left));
	if ((*root)->right != NULL)
		DeleteTree(&((*root)->right));
	delete *root;
	return 0;
}


vector<int> PrintFromTopToBottom(TreeNode* root)
{
	vector<int> res;
	if (root == NULL)
		return res;
	queue<TreeNode*> q;
	q.push(root);
	while (!q.empty())
	{
		res.push_back(q.front()->value);       //����ʱ��queueTreeNode��һ��Ԫ�ش��뵽�������res��
		if (q.front()->left != NULL)       //����ǰ�������㲻Ϊ�գ�����������뵽˫�˶���queueTreeNode��
			q.push(q.front()->left);
		if (q.front()->right != NULL)     ////����ǰ�����ҽ�㲻Ϊ�գ������ҽ����뵽˫�˶���queueTreeNode��
			q.push(q.front()->right);
		q.pop();
	}
	return res;
}

int main(void)
{
	int m;
	TreeNode *root = NULL;
	while (cin >> m)
	{
		num = m;
		if (m == 0)
		{
			cout << "NULL" << endl;
			return 0;
		}
		CreateTree(&root, m);
		PrintFromTopToBottom(root);

		cout << endl;
		DeleteTree(&root);
		root = NULL;
	}

	return 0;
}