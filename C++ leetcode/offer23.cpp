/*****************************************************************************************************
 *         剑指offer第23题
 * 从上往下打印出二叉树的每个节点，同层节点从左至右打印。
 *
 * Input:   二叉树
 * Output:  二叉树的广度优先遍历序列
 *
 * Note:
 *  利用辅助队列实现广度优先遍历。（不管是树或者有向图都用队列实现）
    1.将起始点放到队列中，
	2.接下来每一次从队列的头部取出一个节点，遍历这个节点之后把从它能到达的节点都一次放到队列
	3.重复遍历过程，直到队列中的节点全部被遍历为止
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
		res.push_back(q.front()->value);       //将此时的queueTreeNode第一个元素存入到输出容器res中
		if (q.front()->left != NULL)       //若当前结点的左结点不为空，将其左结点存入到双端队列queueTreeNode中
			q.push(q.front()->left);
		if (q.front()->right != NULL)     ////若当前结点的右结点不为空，将其右结点存入到双端队列queueTreeNode中
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