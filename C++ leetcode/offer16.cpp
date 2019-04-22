/*****************************************************************************************************
 *         剑指offer第16题
 * 输入一个链表，反转链表后，输出新链表的表头。
 *
 * Input:  单向链表的长度以及每个节点的数
 * Output: 反转后的单向链表
 *
 *
 * Note: （结合图分析比较直观）
 * 具体分析见下面的代码分析

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

ListNode* ReverseList(ListNode* Head)
{
	if (Head == NULL)
		return NULL;        //head为当前节点，如果当前节点为空的话，那就什么也不做，直接返回NULL；
	
	ListNode* Pre = NULL; 
	ListNode* Next = NULL;
	//当前节点是head，pre为当前节点的前一节点，next为当前节点的下一节点,需要pre和next的目的是
	//让当前节点从pre->head->next1->next2变成pre<-head next1->next2
	//即pre让节点可以反转所指方向，但反转之后如果不用next节点保存next1节点的话，此单链表就此断开了
	//所以需要用到pre和next两个节点

	while (Head != NULL) //做循环，当前节点不为空的话，始终执行此循环，此循环的目的就是让当前节点从指向next到指向pre
	{
		//如此就可以做到反转链表的效果
		//先用next保存head的下一个节点的信息，保证单链表不会因为失去head节点的原next节点而就此断裂
		Next = Head->next;   
		//保存完next，就可以让head从指向next变成指向pre了
		Head->next = Pre;

		//head指向pre后，就继续依次反转下一个节点
		//让pre，head，next依次向后移动一个节点，继续下一次的指针反转
		Pre = Head;
		Head = Next;
	}
	//如果head为null的时候，pre就为最后一个节点了，但是链表已经反转完毕，pre就是反转后链表的第一个节点
	//直接输出pre就是我们想要得到的反转后的链表
	return Pre;
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
	myList=ReverseList(myList);
	printList(myList, "After reverse: ");

	//删除链表
	while (myList != NULL)
	{
		ListNode* tmp = myList;
		myList = myList->next;
		delete tmp;
	}
}