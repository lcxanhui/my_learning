/*****************************************************************************************************
 *               剑指offer第60题
 * 从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。
 *
 * Input:   二叉树
 * Output:  二叉树的广度优先遍历序列从上到下进行打印
 *
 * Note:（本题参考剑指offer第23题的广度优先遍历即可得到解答）
 *  队列实现,参考offer23

 * author: lcxanhui@163.com
 * time: 2019.7.6
 ******************************************************************************************************/

#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

#define MAX 12

struct TreeNode {
	int value;
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


vector<vector<int> >  Print(TreeNode* root)
{
	vector<vector<int> > res;
	if (root == NULL)
		return res;
	queue<TreeNode*> q;
	q.push(root);
	while (!q.empty())
	{
		vector<int> path; //用于保存当前行的数组
		int len = q.size();
		for(int i=0;i<len;i++)
		{
			TreeNode* node = q.front();
			path.push_back(node->value);
			if (node->left != NULL)
				q.push(node->left);
			if (node->right != NULL)
				q.push(node->right);
			q.pop();
		}
		res.push_back(path);
	}
	return res;
}


int main(void)
{
	int n;
	while (cin >> n)
	{
		TreeNode *root = NULL;
		CreateTree(&root, n);
		vector<vector<int>> res;
		res = Print(root);
		for (int i = 0; i < res.size(); i++)
			for (int j = 0; j < res.size(); i++)
				cout << res[i][j] << " ";
		DeleteTree(&root);
	}

	return 0;
}
