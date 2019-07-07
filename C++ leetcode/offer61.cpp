/*****************************************************************************************************
 *                    ��ָoffer��61��
 * ��ʵ��һ����������֮���δ�ӡ������������һ�а��մ����ҵ�˳���ӡ���ڶ��㰴�մ��������˳���ӡ��
   �����а��մ����ҵ�˳���ӡ���������Դ����ơ�

 * Input:  ������
 * Output: ������֮���δ�ӡ
 *
 * Note:
 * ��ͬ�ڹ�ȱ�������������֮���δ�ӡ�У���Ҫ������ȵ���ż�Խ����߷ֿ�,�����Ҫ����ջ���б���
   1.�����ȴ�ӡ�����㣬�����ȱ�����������ͬ�����Ǹ���ջ���Ƚ���������ԣ�����һ���ӡʱ��Ӧ���Ƚ�node->left
     ���浽����һ��ջ�У�Ȼ��node->right���浽��Ӧ������ջ�У���ô��ӡż����ʱ������ջ���Ƚ���������ԣ�
	 �ͻ����ӡnode->right,�ٴ�ӡnode->left;
  2. �����ӡż���㣬��պ����ȱ�����������ͬ���ȱ���node->right���ٱ���node->left;

  �������ܾ���Ľṹ
				while(��s.empty())
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
//������
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
//ɾ����
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
	vector<vector<int> > res;  //��������ӡ�Ľ��
	if (root == NULL)
		return res;
	stack<TreeNode*> s1, s2;
	s1.push(root);
	while((!s1.empty() || !s2.empty()))
	{
		vector<int> path; //����ĳһ�е�·��
		if (!s1.empty())
		{
			//������Ǻܾ���Ľṹ
			while (!s1.empty())
			{
				//��ӡ�����㣬���շ������ȱ�����һ����󺢣��ڱ����Һ���Ȼ�����ջ���Ƚ�������Է���
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
			//��ӡż���㣬���շ������ȱ�����һ����Һ����ڱ����󺢣�Ȼ�����ջ���Ƚ�������Է���
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