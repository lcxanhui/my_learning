/*****************************************************************************************************
 *                    剑指offer第62题
 * 请实现两个函数，分别用来序列化和反序列化二叉树
 * Input:  二叉树
 * Output: 二叉树序列化和反序列换
 *
 * Note:
 * 本题不做过多阐述，不太清楚题意是啥意思，建议多做leetcode 105和106
 具体参考：
 链接：https://www.nowcoder.com/questionTerminal/cf7e25aa97c04cc1a68c8f040e71fb84

1. 对于序列化：使用前序遍历，递归的将二叉树的值转化为字符，并且在每次二叉树的结点
不为空时，在转化val所得的字符之后添加一个 '，' 作为分割。对于空节点则以 '#' 代替。
 2. 对于反序列化：按照前序顺序，递归的使用字符串中的字符创建一个二叉树(特别注意：
在递归时，递归函数的参数一定要是char *& ，这样才能保证每次递归后指向字符串的指针会
随着递归的进行而移动！！！)

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

//递归调用完成二叉树的序列化
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



//*************************反序列化***********************
//递归调用完成二叉树的反序列化
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