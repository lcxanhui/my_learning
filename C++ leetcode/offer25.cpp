/*****************************************************************************************************
 *         ��ָoffer��25��
 * ����һ�Ŷ������ĸ��ڵ��һ����������ӡ���������н��ֵ�ĺ�Ϊ��������������·����·������Ϊ������
   ����㿪ʼ����һֱ��Ҷ����������Ľ���γ�һ��·����(ע��: �ڷ���ֵ��list�У����鳤�ȴ�����鿿ǰ)
 *
 * Input:  ��������target��sum
 * Output: ����target������
 *
 * Note:������������������㷨DFS������⣩
 *    1.�ݹ������������ �ѽ�����·����
      2.���ý����Ҷ�ӽ����Ƚϵ�ǰ·�����Ƿ�����ڴ��͡�
      3.������㣬ÿһ�ֵݹ鷵�ص������ʱ����ǰ·��ҲӦ�û���һ�����
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
		dfs(root, expectNum, res, tmp);     //DFS�㷨
	return res;
}

void dfs(TreeNode* root, int currentNum, vector<vector<int> > &res, vector<int> &tmp)
{
	tmp.push_back(root->val);        //���ڵ�
	if (root->left == NULL && root->right == NULL)
	{
		if (currentNum == root->val)
			res.push_back(tmp);
	}
	if (root->left != NULL)      //�������ݹ�
		dfs(root->left, currentNum-root->val, res, tmp);
	if (root->right != NULL)     //�������ݹ�
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