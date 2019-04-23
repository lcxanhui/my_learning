/*****************************************************************************************************
 *         剑指offer第18题
 * 输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
 *
 * Input:  两个二叉树
 * Output: 0 or 1
 *
 *
 * Note: (递归思想)
 * 对于两棵二叉树来说，要判断B是不是A的子结构，首先第一步在树A中查找与B根节点的值一样的节点。
   通常对于查找树中某一个节点，我们都是采用递归的方法来遍历整棵树。第二步就是判断树A中以R为根节点的子树
   是不是和树B具有相同的结构。这里同样利用到了递归的方法，如果节点R的值和树的根节点不相同，则以R为根节点
   的子树和树B肯定不具有相同的节点；如果它们值是相同的，则递归的判断各自的左右节点的值是不是相同。递归的
   终止条件是我们达到了树A或者树B的叶节点。
   注意 DoesTree1haveTree2()函数中的两个 if 判断语句 不能颠倒顺序 。
   因为如果颠倒了顺序，会先判断pRoot1是否为None, 其实这个时候，pRoot1的节点已经遍历完成确认相等了，但是
   这个时候会返回 False，判断错误

 * author: lcxanhui@163.com
 * time: 2019.4.23
 ******************************************************************************************************/
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

struct BinaryTreeNode
{
	int value;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
	BinaryTreeNode(int val) {
		value = val;
		left = NULL;
		right = NULL;
	}
};

void CreateTree(BinaryTreeNode **root)
{
	BinaryTreeNode *pNode;
	queue<BinaryTreeNode *> Bqueue;

	int val;
	if (cin >> val && val != -1) {
		*root = new BinaryTreeNode(val);
		Bqueue.push(*root);
	}
	else {
		*root = NULL;
		return;
	}

	while (!Bqueue.empty()) {
		pNode = Bqueue.front();
		Bqueue.pop();
		if (cin >> val) {
			if (val != -1) {
				pNode->left = new BinaryTreeNode(val);
				Bqueue.push(pNode->left);
			}
		}
		else
			break;

		if (cin >> val) {
			if (val != -1) {
				pNode->right = new BinaryTreeNode(val);
				Bqueue.push(pNode->right);
			}
		}
		else
			break;
	}
}

int InOrderRecursion(BinaryTreeNode *root)
{
	if (root == NULL)
		return 0;
	InOrderRecursion(root->left);
	cout << root->value;
	InOrderRecursion(root->right);
	return 0;
}

int InOrderTraverse(BinaryTreeNode *root)
{
	stack<BinaryTreeNode *> stacks;
	BinaryTreeNode *index = root;

	while (index || !stacks.empty())
	{
		if (index)
		{
			stacks.push(index);
			index = index->left;
		}
		else
		{
			index = stacks.top();
			stacks.pop();
			if (index == NULL)
				return -1;
			cout << index->value;
			index = index->right;
		}
	}
	return 0;
}

int DeleteTree(BinaryTreeNode **root)
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

bool DoesTree1HaveTree2(BinaryTreeNode *root1, BinaryTreeNode *root2)
{    // 必须要先遍历Tree2,再遍历Tree1
	//如果Tree2已经遍历完了都能对应的上，返回true
	if (root2 == NULL)
		return true;
//如果Tree2还没有遍历完，Tree1却遍历完了。返回false
	if (root1 == NULL)
		return false;
	if (root1->value != root2->value)
		return false;
//如果根节点对应的上，那么就分别去子节点里面匹配
	return DoesTree1HaveTree2(root1->left, root2->left) &&
		DoesTree1HaveTree2(root1->right, root2->right);
}


bool HasSubtree(BinaryTreeNode *root1, BinaryTreeNode *root2)
{
	if (root1 == NULL || root2 == NULL)
		return false;
	bool result = false;
	//当Tree1和Tree2都不为零的时候，才进行比较。否则直接返回false
	if (root1 != NULL && root2 != NULL)
	{
		//如果找到了对应Tree2的根节点的点
		if (root1->value == root2->value)
			//以这个根节点为为起点判断是否包含Tree2
			result = DoesTree1HaveTree2(root1, root2);
		//如果找不到，那么就再去root的左z子树当作起点，去判断时候包含Tree2
		if (!result)
			result = HasSubtree(root1->left, root2);
		//如果还找不到，那么就再去root的右子树当作起点，去判断时候包含Tree2
		if (!result)
			result = HasSubtree(root1->right, root2);
	}
	return result;
}


int main(void)
{
	bool TF;
	BinaryTreeNode *root1 = NULL, *root2 = NULL;
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);

	CreateTree(&root1);
	CreateTree(&root2);
	InOrderTraverse(root1);
	InOrderTraverse(root2);
	TF = HasSubtree(root1, root2);
	if (TF == true)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	DeleteTree(&root1);
	DeleteTree(&root2);
	root1 = root2 = NULL;

	return 0;
}