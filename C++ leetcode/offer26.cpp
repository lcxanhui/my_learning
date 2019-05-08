/*****************************************************************************************************
 *         ��ָoffer��26��
 * ����һ����������ÿ���ڵ����нڵ�ֵ���Լ�����ָ�룬һ��ָ����һ���ڵ㣬��һ������ָ��ָ������һ��
   �ڵ㣩�����ؽ��Ϊ���ƺ��������head����ע�⣬���������벻Ҫ���ز����еĽڵ����ã�������������ֱ�ӷ��ؿգ�
 *
 * Input:  
 * Output: 
 *
 * Note:������Ĳ���Ҳ̫���׳����ˡ�������
 *    1������ÿ���ڵ㣬�磺���ƽڵ�A�õ�A1����A1����ڵ�A����
      2����������A1->random = A->random->next;
      3���������ֳ�ԭ����͸��ƺ������
 * author: lcxanhui@163.com
 * time: 2019.5.8
 ******************************************************************************************************/

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
#define MAX 1001

struct ComplexListNode {
	int value;
	ComplexListNode *next;
	ComplexListNode *sibling;
};

void Create(int n, ComplexListNode **head)
{
	ComplexListNode* arr[MAX];
	int i, tmp;
	if (n <= 0)
	{
		*head = NULL;
		return;
	}
	for (i = 0; i < n; i++)
	{
		arr[i] = new ComplexListNode;
		arr[i]->next = NULL;
		arr[i]->sibling = NULL;
		arr[i]->value = 0;
	}
	for (i = 0; i < n; i++)
	{
		scanf("%d", &tmp);
		arr[i]->value = tmp;
		if (i != n - 1)
			arr[i]->next = arr[i + 1];
	}
	for (i = 0; i < n; i++)
	{
		scanf("%d", &tmp);
		if (tmp != 0)
			arr[i]->sibling = arr[tmp - 1];
	}
	*head = arr[0];
}

ComplexListNode* Clone(ComplexListNode* head)
{
	if (head == NULL)
		return NULL;
	ComplexListNode* currNode = head;
	//����ÿ���ڵ㣬�磺���ƽڵ�A�õ�A1����A1����ڵ�A����
	while (currNode)
	{
		ComplexListNode* node = new ComplexListNode(currNode->value);
		node->next = currNode->next;
		currNode->next = node;
		currNode = node->next;
	}
	currNode = head;
	//��������A1->random = A->random->next;
	while (currNode)
	{
		ComplexListNode* node = currNode->next;
		if (currNode->sibling)
			node->sibling = currNode->sibling->next;
		currNode = node->next;
	}
	ComplexListNode* pClone = head->next;
	ComplexListNode* tmp;
	currNode = head;
	//�������ֳ�ԭ����͸��ƺ������
	while (currNode->next)
	{
		tmp = currNode->next;
		currNode->next = tmp->next;
		currNode = tmp;
	}
	return pClone;
}

void PrintSibling(ComplexListNode *head)
{
	ComplexListNode *index = head;
	if (index == NULL)
		return;
	while (index)
	{
		if (index->sibling)
			printf("%d %d\n", index->value, index->sibling->value);
		else
			printf("%d 0\n", index->value);
		index = index->next;
	}
}

int main(void)
{
	int n;

	while (cin >> n)
	{
		ComplexListNode *head, *clone_head;
		Create(n, &head);
		clone_head = Clone(head);
		PrintSibling(clone_head);
	}

	return 0;
}
