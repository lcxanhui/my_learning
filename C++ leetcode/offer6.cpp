/*****************************************************************************************************
 *         剑指offer第6题
 * 输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字
 *
 * Input:  前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}
 * Output: 重建二叉树
 *
 *
 * Note: (递归思想)
 * 前序遍历二叉树的第一个数字总是树的根节点的值，在中序遍历中找到对应的根节点的位置，可以将二叉树分为
   左子树和右子树，通过递归调用重构二叉树。
   同样后续遍历的最后一个数字为输的根节点的值，利用同样方法重建二叉树。

 *****本程序有错误，TreeNode* root = new TreeNode(root)该语句将TreeNode的指针指向int型，不知怎么修改
 * authur: lcxanhui@163.com
 * time: 2019.4.18
 ******************************************************************************************************/
#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
};

TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin)
{
	int vinlength = vin.size();
	int prelength = pre.size();
	if (prelength == 0 || vinlength==0)
		return NULL;
	int root = pre[0];
	TreeNode* root = new TreeNode(root);

	vector<int> pre_left, pre_right, vin_left, vin_right;
	int gen;
	for (int i = 0; i < prelength; i++)
	{
		if (vin[i] == root)
		{
			gen = i;
			break;
		}
	}
	for (int i = 0; i < gen; i++)
	{
		vin_left.push_back(vin[i]);
		pre_left.push_back(pre[i+1]);    //注意前序遍历的第一个为根节点
	}
	for (int i = gen + 1; i < vinlength; i++)
	{
		vin_right.push_back(vin[i]);
		pre_right.push_back(pre[i]);
	}
	root->left = reConstructBinaryTree(pre_left, vin_left);
	root->right = reConstructBinaryTree(pre_right, vin_right);
	return root;
}

int main()
{
	vector<int> pre = { 1, 2, 4, 7, 3, 5, 6, 8 };
	vector<int> vin = { 4, 7, 2, 1, 5, 3, 8, 6 };
	TreeNode* root = reConstructBinaryTree(pre, vin);

	system("pause");
	return 0;
}