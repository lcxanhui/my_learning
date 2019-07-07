/*****************************************************************************************************
 *                    剑指offer第61题
 * 请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右至左的顺序打印，
   第三行按照从左到右的顺序打印，其他行以此类推。

 * Input:  二叉树
 * Output: 二叉树之字形打印
 *
 * Note:
 * 不同于广度遍历二叉树，在之字形打印中，需要按照深度的奇偶性将两者分开,因此需要两个栈进行保存
   1.假设先打印奇数层，则与广度遍历二叉树相同，但是根据栈的先进后出的特性，在下一层打印时，应该先将node->left
     保存到另外一个栈中，然后将node->right保存到相应的另外栈中，那么打印偶数层时，根据栈的先进后出的特性，
	 就会想打印node->right,再打印node->left;
  2. 假设打印偶数层，则刚好与广度遍历二叉树不同，先保存node->right，再保存node->left;

  二叉树很经典的结构
				while(！s.empty())
				{	
					if()
					.....
					if()
				}

 * author: lcxanhui@163.com
 * time: 2019.7.6
 ******************************************************************************************************/

#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>
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

vector<vector<int> > Print(TreeNode *root)
{
	vector<vector<int> > res;  //保存最后打印的结果
	if (root == NULL)
		return res;
	stack<TreeNode*> s1, s2;
	s1.push(root);
	while((!s1.empty() || !s2.empty()))
	{
		vector<int> path; //保存某一行的路径
		if (!s1.empty())
		{
			//下面就是很经典的结构
			while (!s1.empty())
			{
				//打印奇数层，按照分析，先保存下一层的左孩，在保存右孩，然后根据栈的先进后出特性符合
				TreeNode* node = s1.top();
				path.push_back(node->val);
				s1.pop();
				if (node->left != NULL)
					s2.push(node->left);
				if (node->right != NULL)
					s2.push(node->right);
			}
			res.push_back(path);
		}
		else if (!s2.empty()) {
			//打印偶数层，按照分析，先保存下一层的右孩，在保存左孩，然后根据栈的先进后出特性符合
			while (!s2.empty())
			{
				TreeNode* node = s2.top();
				path.push_back(node->val);
				s2.pop();
				if (node->right != NULL)
					s1.push(node->right);
				if (node->left != NULL)
					s1.push(node->left);
			}
			res.push_back(path);
		}
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