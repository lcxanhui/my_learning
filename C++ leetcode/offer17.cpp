/*****************************************************************************************************
 *         剑指offer第16题
 * 输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
 *
 * Input:  两个单向链表的长度以及每个节点的数（单调不减）
 * Output: 合并后的链表
 *
 *
 * Note: （结合图分析比较直观）
 * 较为简单的递归算法，但是复杂度较高，可以考虑其他算法
 * author: lcxanhui@163.com
 * time: 2019.4.22
 ******************************************************************************************************/

#include<iostream>
#include<stack>
#include<string>
using namespace std;

//定义链表结构
struct ListNode
{
	int value;
	ListNode* next;
	//ListNode(int x) :value(x), next(NULL) {}
};

void createList(ListNode*& myList, int listLength)
{
	ListNode* head1 = NULL;
	for (int i = 0; i < listLength; i++)
	{
		if (head1 == NULL)
		{
			int t;
			head1 = new ListNode;
			cin >> t;
			head1->value = t;
			head1->next = NULL;
			myList = head1;
		}
		else
		{
			int t;
			head1->next = new ListNode;
			head1 = head1->next;
			cin >> t;
			head1->value = t;
			head1->next = NULL;
		}
	}
}

//打印链表
void printList(ListNode* head, string name)
{
	cout << name;
	while (head != NULL)
	{
		cout << head->value << "->";
		head = head->next;
	}
	cout << "NULL" << endl;
}

void deleteList(ListNode* head)
{
	while (head != NULL)
	{
		ListNode* tmp = head;
		head = head->next;
		delete tmp;
		tmp = NULL;
	}
}


ListNode* Merge(ListNode* Head1,ListNode* Head2)
{    //head1为当前节点，如果当前节点为空的话，那就什么也不做，直接返回head2；同理head2；
	if (Head1 == NULL)
		return Head2; 
	else if (Head2 == NULL)
		return Head1; 
	
	ListNode* MergeHead = NULL;
	if (Head1->value < Head2->value)
	{
		MergeHead = Head1;
		MergeHead->next=Merge(Head1->next,Head2);   //递归算法
	}
	else 
	{
		MergeHead = Head2;
		MergeHead->next = Merge(Head1, Head2->next);
	}
	return MergeHead;
}

int main()
{
	ListNode* myList1 = NULL;
	ListNode* head1 = NULL;
	int listLength;
	cout << "listLength:";
	cin >> listLength;
	cout << "Please input " << listLength << " numbers" << endl;
	createList(myList1, listLength);
	printList(myList1, "myList1: ");

	ListNode* myList2 = NULL;
	ListNode* head2 = NULL;
	int listLength2;
	cout << "listLength2:";
	cin >> listLength2;
	cout << "Please input " << listLength2 << " numbers" << endl;
	createList(myList2, listLength2);
	printList(myList2, "myList2: ");

	printList(Merge(myList1, myList2), "After merge: ");

	//删除链表
	//deleteList(myList1);
	//deleteList(myList2);
}