/*****************************************************************************************************
 *                    ��ָoffer��62��
 * ��ʵ�������������ֱ��������л��ͷ����л�������
 * Input:  ������
 * Output: ���������л��ͷ����л�
 *
 * Note:
 * ���ⲻ�������������̫���������ɶ��˼���������leetcode 105��106
 ����ο���
 ���ӣ�https://www.nowcoder.com/questionTerminal/cf7e25aa97c04cc1a68c8f040e71fb84

1. �������л���ʹ��ǰ��������ݹ�Ľ���������ֵת��Ϊ�ַ���������ÿ�ζ������Ľ��
��Ϊ��ʱ����ת��val���õ��ַ�֮�����һ�� '��' ��Ϊ�ָ���ڿսڵ����� '#' ���档
 2. ���ڷ����л�������ǰ��˳�򣬵ݹ��ʹ���ַ����е��ַ�����һ��������(�ر�ע�⣺
�ڵݹ�ʱ���ݹ麯���Ĳ���һ��Ҫ��char *& ���������ܱ�֤ÿ�εݹ��ָ���ַ�����ָ���
���ŵݹ�Ľ��ж��ƶ�������)

 * author: lcxanhui@163.com
 * time: 2019.7.7
 ******************************************************************************************************/


#include<iostream>
#include<string>
#include<cstdio>
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

//�ݹ������ɶ����������л�
void Serialize(TreeNode* root, string& str) {
	if (root == NULL)
	{
		str += '#';
		return;
	}
	string r = to_string(root->val);
	str += r;
	str += '\0';
	Serialize(root->left, str);
	Serialize(root->right, str);
}
char* Serialize(TreeNode* root)
{
	if (root == NULL)
		return NULL;
	string str;
	Serialize(root, str);
	char *ret = new char[str.length() + 1];
	int i;
	for (i = 0; i < str.length(); i++)
	{
		ret[i] = str[i];
	}
	ret[i] = '\0';
	return ret;
}



//*************************�����л�***********************
//�ݹ������ɶ������ķ����л�
TreeNode* aDeserialize(char *&str)
{
	if (*str == '#')
	{
		str++;
		return NULL;
	}
	int num = 0;
	while (*str != '\0'&&*str != ',')
	{
		num = num * 10 + ((*str) - '\0');
		(str)++;
	}
	TreeNode* root = new TreeNode(num);
	if (*str == '\0')
		return root;
	else
		(str)++;
	root->left = aDeserialize(str);
	root->right = aDeserialize(str);
}

TreeNode* Deserialize(char *str)
{
	if (str == NULL)
		return NULL;
	TreeNode* ret = aDeserialize(str);

	return ret;
}

int main()
{
	int n;
	while (cin >> n)
	{
		TreeNode *root = NULL;
		CreateTree(&root, n);
		Serialize(root);
		DeleteTree(&root);
	}

	return 0;
}