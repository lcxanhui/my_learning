/*****************************************************************************************************
 *                    剑指offer第63题
 * 给定一棵二叉搜索树，请找出其中的第k小的结点。例（5，3，7，2，4，6，8）中，按结点数值大小顺序第三小结点的值为4。
 * Input:  二叉树
 * Output: 二叉树第K小的节点数
 *
 * Note:（二叉树非递归的前、中、后序遍历必须要熟悉）--后序最难
 * 本题要用到二叉树的中序遍历，因为中序遍历的二叉树是从小到大进行排列的，因此可以直接利用二叉树的前序遍历的
   非递归写法，只是在中间增加计数即可，关键在于对基础的掌握程度

******************本题编程已通过*********************
  二叉树非递归很经典的结构前序和中序都用stack结构
				while(!s.empty()||node!=NULL)
				{
					while(node!=NULL)
					.....
					if(!s.empty())
				}
 * author: lcxanhui@163.com
 * time: 2019.7.8
 ******************************************************************************************************/

#include<iostream>
#include<stack>
#include<queue>

using namespace std;

//树结构体
struct TreeNode {
	int value;
	TreeNode * left;
	TreeNode * right;
	TreeNode(int value) :value(value), left(NULL), right(NULL) {}
};

//构建二叉树
void insertTreeNode(TreeNode *node, int value) {
	if (value <= node->value) {
		if (!node->left) {
			node->left = new TreeNode(value);
		}
		else {
			insertTreeNode(node->left, value);
		}
	}
	else {
		if (!node->right) {
			node->right = new TreeNode(value);
		}
		else {
			insertTreeNode(node->right, value);
		}
	}
}

//中序遍历非递归实现,只是在非递归实现中增加了出栈的简单计数
TreeNode* inOrder(TreeNode *root,unsigned int k) {
	if (root == NULL || k == 0)
		return NULL;
	stack<TreeNode*> nstack;
	TreeNode *temp = root;
	int count = 0;
	while (temp !=NULL || !nstack.empty()) 
	{
		while(temp!=NULL) 
		{
			nstack.push(temp);
			temp = temp->left;
		}
		if(!nstack.empty())
		{
			temp = nstack.top();
			cout << temp->value<<" ";
			nstack.pop();
			//出栈的简单计数判断
			count++;
			if (count == k)
				return temp;
			//左子树不存在，则下面同样看右子树
			else
				temp = temp->right;
		}
	}
	return temp;
}

int main() 
{
	int n,k;
	cin >> k;
	while (cin >> n) {
		n--;
		int value;
		cin >> value;
		TreeNode root(value);
		while (n--) {
			int newValue;
			cin >> newValue;
			insertTreeNode(&root, newValue);
		}

		TreeNode *res = NULL;
		cout << "inOrder without recursion is:";
		res=inOrder(&root,k);
		cout << endl;
		cout <<"The Node is:" <<res->value <<endl;
		system("pause");
		return 0;
	}
}
