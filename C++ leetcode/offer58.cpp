/*****************************************************************************************************
 *         ��ָoffer��58��
 * ����һ�������������е�һ����㣬���ҳ��������˳�����һ����㲢�ҷ��ء�ע�⣬���еĽ�㲻����������
   �ӽ�㣬ͬʱ����ָ�򸸽���ָ�롣
 *
 * Input:  ��������Ķ�����
 * Output: ������ĳһ�ڵ����һ�ڵ�
 *
 * Note:
 * ��������������һ���ڵ㣬һ�������������
  1.������Ϊ�գ��򷵻ؿգ�
  2.�ڵ��Һ��Ӵ��ڣ�������һ��ָ��Ӹýڵ���Һ��ӳ�����һֱ����ָ�����ӽ���ָ���ҵ���Ҷ�ӽڵ㼴Ϊ��һ���ڵ㣻
  3.�ڵ㲻�Ǹ��ڵ㡣 
     ����ýڵ����丸�ڵ�����ӣ��򷵻ظ��ڵ㣻
	 ����������ϱ����丸�ڵ�ĸ��ڵ㣬�ظ�֮ǰ���жϣ����ؽ����

 * author: lcxanhui@163.com
 * time: 2019.7.5
 ******************************************************************************************************/

#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

#define MAX 12

struct TreeLinkNode {
	int val;
	struct TreeLinkNode *left;
	struct TreeLinkNode *right;
	struct TreeLinkNode *next;
	//TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
	//}
};
//������
void CreateTree(TreeLinkNode **root, int n)
{
	if (n <= 0)
		return;
	TreeLinkNode* arr[MAX];

	for (int i = 0; i < n; i++)
	{
		arr[i] = new TreeLinkNode;
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
void DeleteTree(TreeLinkNode **root)
{
	if ((*root) == NULL)
		return;
	DeleteTree(&((*root)->left));
	DeleteTree(&((*root)->right));
	delete *root;
}


TreeLinkNode* GetNext(TreeLinkNode *root)
{
	if (root == NULL)
		return NULL;
	//�ýڵ���������������£��ҵ���������������Ľڵ�
	if (root->right != NULL)
	{
		root=root->right;
		while (root->left != NULL)
			root = root->left;
		return root;
	}
	//û��������������·�Ϊ�����������
	else
	{
		while (root->next != NULL)  //��ֹΪ���ڵ�����
		{
			TreeLinkNode* proot = root->next;
			if (proot->left == root)//���Ӻ���û��������
				return proot;
			root = root->next;  //�������������Ӻ�����û��������ֱ��ָ�򸸽ڵ�
		}
	}
	return NULL;
}

int main(void)
{
	int n;
	while (cin >> n)
	{
		TreeLinkNode *root = NULL;
		CreateTree(&root, n);
		GetNext(root);
		DeleteTree(&root);
	}

	return 0;
}