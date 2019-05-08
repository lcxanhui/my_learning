/*****************************************************************************************************
 *         剑指offer第26题
 * 输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个
   节点），返回结果为复制后复杂链表的head。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
 *
 * Input:  
 * Output: 
 *
 * Note:（链表的操作也太容易出错了。。。）
 *    1、复制每个节点，如：复制节点A得到A1，将A1插入节点A后面
      2、遍历链表，A1->random = A->random->next;
      3、将链表拆分成原链表和复制后的链表
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
	//复制每个节点，如：复制节点A得到A1，将A1插入节点A后面
	while (currNode)
	{
		ComplexListNode* node = new ComplexListNode(currNode->value);
		node->next = currNode->next;
		currNode->next = node;
		currNode = node->next;
	}
	currNode = head;
	//遍历链表，A1->random = A->random->next;
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
	//将链表拆分成原链表和复制后的链表
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
