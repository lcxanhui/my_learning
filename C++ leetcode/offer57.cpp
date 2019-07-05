/*****************************************************************************************************
 *         剑指offer第57题
 * 在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 
   例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
 *
 * Input:  链表
 * Output: 删除重复数据后的链表
 *
 * Note: 
 * 非递归的代码：
   1. 首先添加一个头节点，以方便碰到第一个，第二个节点就相同的情况
   2.设置 pre，last 指针，pre指针指向当前确定不重复的那个节点，而last指针相当于工作指针，一直往后面搜索。
 * author: lcxanhui@163.com
 * time: 2019.6.30
 ******************************************************************************************************/

#include <iostream>
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

// 删除排序链表的相同的节点
ListNode* DelDuplication(ListNode *head)
{
	if (head == NULL||head->next==NULL)
		return head;
	ListNode* newhead = new ListNode(); //设置时的一个trick,防止头结点和后一个节点也是重复的
	newhead->next = head;
	ListNode* pre = newhead;
	ListNode* last = newhead->next;//防止head节点与后面的重复的情况
	while (last->next != NULL)
	{
		if (last->next != NULL && last->value == last->next->value)
		{
			while (last->next != NULL && last->value == last->next->value)//当前节点和后一个节点重复，则指向后面的节点
			{
				last = last->next;
			}
			pre->next = last->next; //此时pre->next指向last->next,也就是将重复的节点也删除
			last = last->next;
		}
		else {
			pre = pre->next;
			last = last->next;
		}
	}
	return newhead->next;
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
	myList = DelDuplication(myList);
	printList(myList, "After Delete: ");

	//删除链表
	while (myList != NULL)
	{
		ListNode* tmp = myList;
		myList = myList->next;
		delete tmp;
	}
}