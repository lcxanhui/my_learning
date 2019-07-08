/*****************************************************************************************************
 *                    ��ָoffer��63��
 * ����һ�ö��������������ҳ����еĵ�kС�Ľ�㡣����5��3��7��2��4��6��8���У��������ֵ��С˳�����С����ֵΪ4��
 * Input:  ������
 * Output: ��������KС�Ľڵ���
 *
 * Note:���������ǵݹ��ǰ���С������������Ҫ��Ϥ��--��������
 * ����Ҫ�õ��������������������Ϊ��������Ķ������Ǵ�С����������еģ���˿���ֱ�����ö�������ǰ�������
   �ǵݹ�д����ֻ�����м����Ӽ������ɣ��ؼ����ڶԻ��������ճ̶�

******************��������ͨ��*********************
  �������ǵݹ�ܾ���Ľṹǰ���������stack�ṹ
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

//���ṹ��
struct TreeNode {
	int value;
	TreeNode * left;
	TreeNode * right;
	TreeNode(int value) :value(value), left(NULL), right(NULL) {}
};

//����������
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

//��������ǵݹ�ʵ��,ֻ���ڷǵݹ�ʵ���������˳�ջ�ļ򵥼���
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
			//��ջ�ļ򵥼����ж�
			count++;
			if (count == k)
				return temp;
			//�����������ڣ�������ͬ����������
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
