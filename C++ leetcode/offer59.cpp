/*****************************************************************************************************
 *                    ��ָoffer��59��
 * ��ʵ��һ�������������ж�һ�Ŷ������ǲ��ǶԳƵġ�ע�⣬���һ��������ͬ�˶������ľ�����ͬ���ģ�������Ϊ�ԳƵġ�
 *
 * Input:  ������
 * Output: �������Ƿ��ǶԳƵ�
 *
 * Note:(�����Ϊ�ݹ�ͷǵݹ���������ص����շǵݹ������)
 * ˼·������ͬ�ģ�
   ���ϵ��µݹ�������Ƚ����������������ֱ��λ�Ƚϣ�
   ������������ڵ������������ҽڵ�Ƚϣ����������ҽڵ�������������ڵ�Ƚ�

 * author: lcxanhui@163.com
 * time: 2019.7.6
 ******************************************************************************************************/

#include <iostream>
#include <cstdio>
#include <stack>
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
//�ݹ��������Ƚϼ�
//bool isSame(TreeNode *p1, TreeNode *p2)
//{
//	if (p1->left == NULL && p2->right == NULL)
//		return true;
//	if (p1->left != NULL && p2->right == NULL)
//		return false;
//	if (p1->left == NULL && p2->right != NULL)
//		return false;
//	if (p1->val == p2->val)
//		return isSame(p1->left, p2->right) && isSame(p1->right, p2->left);
//	return false;
//}
//
//bool isSymmetrical(TreeNode *root)
//{
//	if (root == NULL)
//		return true;
//	return isSame(root->left, root->right);
//}



//�ǵݹ���������Ҫ�õ�stack��ÿ�ηǵݹ�����ṹ��������Ҫ�õ�stack�ṹ����Ҫ��������
bool isSymmetrical(TreeNode *root)
{
	if (root == NULL)
		return true;
	stack<TreeNode*> s1, s2;
	TreeNode *p1, *p2;
	p1 = p2 = root;
	while ((!s1.empty() && !s2.empty()) || (p1 != NULL && p2 != NULL))
	{
		while (p1 != NULL && p2 != NULL)
		{
			s1.push(p1);
			s2.push(p2);
			p1 = p1->left;
			p2 = p2->right;
		}
		p1 = s1.top();
		p2 = s2.top();
		s1.pop();
		s2.pop();
		if (p1->val != p2->val)
			return false;
		p1 = p1->right;
		p2 = p2->left;
	}
	if (!s1.empty() || !s2.empty())
		return false;
	if(p1 != NULL && p2 != NULL)
		return false;
	return true;
}

int main(void)
{
	int n;
	while (cin >> n)
	{
		TreeNode *root = NULL;
		CreateTree(&root, n);
		bool res=isSymmetrical(root);
		DeleteTree(&root);
	}

	return 0;
}