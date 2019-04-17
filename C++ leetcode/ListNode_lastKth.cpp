/*****************************************************************************************************
 *         剑指offer第15题
 *输入一个链表，输出该链表中倒数第k个结点。
 *
 * Input:  单向链表的长度以及每个节点的数
 * Output: 单向链表倒数第k个节点的数
 *
 *
 * Note:(快慢指针)
 * 由于是单链表，我们不知道链表长度n，不然我们完全可以只走（n-k）步。最简单的获取链表长度的方法就是
 * 遍历一遍链表，然后再从头开始走（n-k）个。如果链表的结点数不多，这是一种很好的方法。但如果输入的链
 * 表的结点个数很多，有可能不能一次性把整个链表都从硬盘读入物理内存，那么遍历两遍意味着一个结点需要
 * 两次从硬盘读入到物理内存。我们知道把数据从硬盘读入到内存是非常耗时间的操作。我们能不能把链表遍历
 * 的次数减少到1？如果可以，将能有效地提高代码执行的时间效率。如果我们在遍历时维持两个指针，第一个
 * 指针从链表的头指针开始遍历，在第k-1步之前，第二个指针保持不动；在第k-1步开始，第二个指针也开始从
 * 链表的头指针开始遍历。由于两个指针的距离保持在k-1，当第一个（走在前面的）指针到达链表的尾结点时，
 * 第二个指针（走在后面的）指针正好是倒数第k个结点。这种思路只需要遍历链表一次。对于很长的链表，只需
 * 要把每个结点从硬盘导入到内存一次。因此这一方法的时间效率前面的方法要高。
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

//寻找链表倒数第K个元素
ListNode* FindkthToEnd(ListNode *myList, unsigned int k)
{
	//k 必须至少是1，因为链表的最后一个结点是NULL（特殊输入判断）
	if ((myList == NULL) || (k <= 0))
	{
		cout << "myList is NULL or k <= 0." << endl;
		return NULL;
	}
	//快慢指针的变种，先后指针
	ListNode* first = myList;
	ListNode* second = myList;
	// 让first指针先走k步
	while (k > 0)
	{
		if (first == NULL)
		{
			break;
		}
		k--;
		first = first->next;
	}
	if (k > 0)
	{
		cout << "k is longer than than the total length of the list!" << endl;
		return NULL;
	}
	printList(first, "first: ");
	// first and second指针都走，当second指针到链表尾部时，first指针指的就是倒数第k个结点
	while (first != NULL)
	{
		first = first->next;
		second = second->next;
	}
	return second;
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

	int k;
	cout << "Find the kth value from the end: ";
	cin >> k;
	ListNode* kthNode = FindkthToEnd(myList, k);
	if (kthNode != NULL)
	{
		cout << "The " << k << "-th value from the end is: " << kthNode->value << endl;
	}
	//删除链表
	while (myList != NULL)
	{
		ListNode* tmp = myList;
		myList = myList->next;
		delete tmp;
	}
}
