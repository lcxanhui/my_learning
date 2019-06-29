/*****************************************************************************************************
 *         剑指offer第56题
 * 给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。
 *
 * Input:  链表
 * Output: 若链表中有环，则返回环的入口节点
 *
 *
 * Note: （快慢指针典型，面试经常遇到
 * 本题是LeetCode 142题，很经典的题目，其中Floyd算法进行证明，是本题目解题的基础）
 * 先说Floyd定理：两个指针一个fast、一个slow同时从一个链表的头部出发
    fast一次走2步，slow一次走一步，如果该链表有环，两个指针必然在环内相遇
    此时只需要把其中的一个指针重新指向链表头部，另一个不变（还在环内），
    这次两个指针一次走一步，相遇的地方就是入口节点。

 * author: lcxanhui@163.com
 * time: 2019.6.29
 ******************************************************************************************************/

#include <iostream>
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

// 找到链表中第一个相遇时的节点
ListNode* meetingNode(ListNode *head)
{
	if (head == NULL)
		return NULL;
	ListNode* fast = head;
	ListNode* slow = head;
	while (fast != NULL && fast->next != NULL)    //注意此判定条件，while非if
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
			return fast;
	}
	return NULL;
}

//一个指针重新指向链表头部head,另外一个指向链表相遇的节点，当两者相遇，即为最终环的入口
ListNode* FirstNodeInList(ListNode *head)
{
	if (head == NULL)
		return NULL;
	ListNode* meetNode = meetingNode(head);
	if (meetNode == NULL)
		return NULL;
	ListNode* fir = head;
	ListNode* sec = meetNode;
	while (fir != sec)
	{
		fir = fir->next;
		sec = sec->next;
	}
	return sec;
}

int main()
{
	ListNode* myList = NULL;
	ListNode* head = NULL;
	int listLength;
	cout << "listLength:";
	cin >> listLength;
	cout << "Please input " << listLength << " numbers" << endl;
	for (int i = 0; i < listLength; i++)
	{
		if (head == NULL)
		{
			int t;
			head = new ListNode;
			cin >> t;
			head->value = t;
			head->next = NULL;
			myList = head;
		}
		else
		{
			int t;
			head->next = new ListNode;
			head = head->next;
			cin >> t;
			head->value = t;
			head->next = NULL;
		}
	}
	printList(myList, "myList: ");
	myList = FirstNodeInList(myList);
	printList(myList, "First Node In Cycle Pos: ");

	//删除链表
	while (myList != NULL)
	{
		ListNode* tmp = myList;
		myList = myList->next;
		delete tmp;
	}
}