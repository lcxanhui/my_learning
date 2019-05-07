/*****************************************************************************************************
 *         剑指offer第25题
 * 输入一颗二叉树的跟节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。路径定义为从树的
   根结点开始往下一直到叶结点所经过的结点形成一条路径。(注意: 在返回值的list中，数组长度大的数组靠前)
 *
 * Input:  二叉树和target的sum
 * Output: 符合target的序列
 *
 * Note:（利用深度优先搜索算法DFS进行求解）
 *    1.递归先序遍历树， 把结点加入路径。
      2.若该结点是叶子结点则比较当前路径和是否等于期待和。
      3.弹出结点，每一轮递归返回到父结点时，当前路径也应该回退一个结点
 * author: lcxanhui@163.com
 * time: 2019.5.7
 ******************************************************************************************************/

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
};

void dfs(TreeNode* root, int currentNum, vector<vector<int> > &res, vector<int> &tmp);
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
	(*root)->val = num[0];
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
			tmpNode->val = num[tmp - 1];
			tmpNode->left = NULL;
			tmpNode->right = NULL;
			index->left = tmpNode;
			Bqueue.push(tmpNode);
			cin >> tmp;
			tmpNode = new TreeNode;
			tmpNode->val = num[tmp - 1];
			tmpNode->left = NULL;
			tmpNode->right = NULL;
			index->right = tmpNode;
			Bqueue.push(tmpNode);
		}
		else if (child_num == 'l')
		{
			cin >> tmp;
			tmpNode = new TreeNode;
			tmpNode->val = num[tmp - 1];
			tmpNode->left = NULL;
			tmpNode->right = NULL;
			index->left = tmpNode;
			Bqueue.push(tmpNode);
		}
		else if (child_num == 'r')
		{
			cin >> tmp;
			tmpNode = new TreeNode;
			tmpNode->val = num[tmp - 1];
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


vector<vector<int> > Findpath(TreeNode* root,int expectNum)
{
	vector<vector<int> > res;
	vector<int> tmp;
	if (root == NULL)
		return res;
	if (root != NULL)
		dfs(root, expectNum, res, tmp);     //DFS算法
	return res;
}

void dfs(TreeNode* root, int currentNum, vector<vector<int> > &res, vector<int> &tmp)
{
	tmp.push_back(root->val);        //根节点
	if (root->left == NULL && root->right == NULL)
	{
		if (currentNum == root->val)
			res.push_back(tmp);
	}
	if (root->left != NULL)      //左子树递归
		dfs(root->left, currentNum-root->val, res, tmp);
	if (root->right != NULL)     //右子树递归
		dfs(root->right, currentNum - root->val, res, tmp);
	tmp.pop_back();

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
		
		int target;
		cin >> target;
		vector<vector<int> > res;
		res = Findpath(root, target);

		DeleteTree(&root);
		root = NULL;
	}

	return 0;
}