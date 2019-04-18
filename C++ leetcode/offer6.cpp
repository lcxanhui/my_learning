/*****************************************************************************************************
 *         ��ָoffer��6��
 * ����ĳ��������ǰ���������������Ľ�������ؽ����ö����������������ǰ���������������Ľ���ж������ظ�������
 *
 * Input:  ǰ���������{1,2,4,7,3,5,6,8}�������������{4,7,2,1,5,3,8,6}
 * Output: �ؽ�������
 *
 *
 * Note: (�ݹ�˼��)
 * ǰ������������ĵ�һ�������������ĸ��ڵ��ֵ��������������ҵ���Ӧ�ĸ��ڵ��λ�ã����Խ���������Ϊ
   ����������������ͨ���ݹ�����ع���������
   ͬ���������������һ������Ϊ��ĸ��ڵ��ֵ������ͬ�������ؽ���������

 *****�������д���TreeNode* root = new TreeNode(root)����佫TreeNode��ָ��ָ��int�ͣ���֪��ô�޸�
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
		pre_left.push_back(pre[i+1]);    //ע��ǰ������ĵ�һ��Ϊ���ڵ�
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