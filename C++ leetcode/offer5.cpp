/*****************************************************************************************************
 *         剑指offer第5题
 * 输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。。
 *
 * Input:  单向链表的长度以及每个节点的数
 * Output: 单向链表的从尾到头
 *
 *
 * Note: (递归思想)
 * 递归打印即可，不过链表很大的话，递归会耗尽栈空间，所以最好还是使用堆里的内存自己维护一个栈。
 * authur: lcxanhui@163.com 
 * time: 2019.4.17
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

void printListInReversedOrder(ListNode* head)
{
	if (head == NULL)
		return;
	if (head->next == NULL)
	{
		cout << head->value << "->";
		return;
	}
	//先打印后面的，在打印当前节点	
	printListInReversedOrder(head->next);        //树结构常用方法：递归调用思想
	cout << head->value << "->";
	return;
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
	printListInReversedOrder(myList);

	//删除链表
	while (myList != NULL)
	{
		ListNode* tmp = myList;
		myList = myList->next;
		delete tmp;
	}
}