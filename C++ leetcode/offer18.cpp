/*****************************************************************************************************
 *         ��ָoffer��18��
 * �������ö�����A��B���ж�B�ǲ���A���ӽṹ����ps������Լ��������������һ�������ӽṹ��
 *
 * Input:  ����������
 * Output: 0 or 1
 *
 *
 * Note: (�ݹ�˼��)
 * �������ö�������˵��Ҫ�ж�B�ǲ���A���ӽṹ�����ȵ�һ������A�в�����B���ڵ��ֵһ���Ľڵ㡣
   ͨ�����ڲ�������ĳһ���ڵ㣬���Ƕ��ǲ��õݹ�ķ������������������ڶ��������ж���A����RΪ���ڵ������
   �ǲ��Ǻ���B������ͬ�Ľṹ������ͬ�����õ��˵ݹ�ķ���������ڵ�R��ֵ�����ĸ��ڵ㲻��ͬ������RΪ���ڵ�
   ����������B�϶���������ͬ�Ľڵ㣻�������ֵ����ͬ�ģ���ݹ���жϸ��Ե����ҽڵ��ֵ�ǲ�����ͬ���ݹ��
   ��ֹ���������Ǵﵽ����A������B��Ҷ�ڵ㡣
   ע�� DoesTree1haveTree2()�����е����� if �ж���� ���ܵߵ�˳�� ��
   ��Ϊ����ߵ���˳�򣬻����ж�pRoot1�Ƿ�ΪNone, ��ʵ���ʱ��pRoot1�Ľڵ��Ѿ��������ȷ������ˣ�����
   ���ʱ��᷵�� False���жϴ���

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
{    // ����Ҫ�ȱ���Tree2,�ٱ���Tree1
	//���Tree2�Ѿ��������˶��ܶ�Ӧ���ϣ�����true
	if (root2 == NULL)
		return true;
//���Tree2��û�б����꣬Tree1ȴ�������ˡ�����false
	if (root1 == NULL)
		return false;
	if (root1->value != root2->value)
		return false;
//������ڵ��Ӧ���ϣ���ô�ͷֱ�ȥ�ӽڵ�����ƥ��
	return DoesTree1HaveTree2(root1->left, root2->left) &&
		DoesTree1HaveTree2(root1->right, root2->right);
}


bool HasSubtree(BinaryTreeNode *root1, BinaryTreeNode *root2)
{
	if (root1 == NULL || root2 == NULL)
		return false;
	bool result = false;
	//��Tree1��Tree2����Ϊ���ʱ�򣬲Ž��бȽϡ�����ֱ�ӷ���false
	if (root1 != NULL && root2 != NULL)
	{
		//����ҵ��˶�ӦTree2�ĸ��ڵ�ĵ�
		if (root1->value == root2->value)
			//��������ڵ�ΪΪ����ж��Ƿ����Tree2
			result = DoesTree1HaveTree2(root1, root2);
		//����Ҳ�������ô����ȥroot����z����������㣬ȥ�ж�ʱ�����Tree2
		if (!result)
			result = HasSubtree(root1->left, root2);
		//������Ҳ�������ô����ȥroot��������������㣬ȥ�ж�ʱ�����Tree2
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