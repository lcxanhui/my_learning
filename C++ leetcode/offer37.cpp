/*****************************************************************************************************
 *         剑指offer第37题
 * 输入两个链表，找出它们的第一个公共结点。
 *
 * Input:  两个单向链表每个节点的数
 * Output: 两个链表的第一个公共结点
 *
 * Note: （此题还可以用同样的思路求取二叉树的最低的公共祖先）
 *  1. 找出2个链表的长度，
    2.然后让长的先走两个链表的长度差，
	3.然后再一起走，直至遍历到相同的值
  （因为2个链表用公共的尾部，时间复杂度O(mn)）

  另外提供的方法不需要获取链表的长度，类似于快慢指针的思路
 * author: lcxanhui@163.com
 * time: 2019.5.19
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

// 获取链表的长度，用于后序比较两个链表
int GetLenOfList(ListNode *head)
{
	int len = 0;
	while (head!=NULL)
	{
		len++;
		head = head->next;
	}
	return len;
}

// 对于较长的链表，先走两个链表差值的长度
ListNode* walkstep(ListNode* head, int len)
{
	for (int i = 0; i < len; i++)
	{
		head = head->next;
	}
	return head;
}

int FirstCommonNode(ListNode* head1, ListNode* head2)
{
	int len1 = GetLenOfList(head1);   //分别获取链表1和链表2的长度
	int len2 = GetLenOfList(head2);
	if (len2 > len1)
		head2 = walkstep(head2, len2 - len1);
	else
		head1 = walkstep(head1, len1 - len2);    //对于较长长度的链表，先走两个链表长度的差值，使得两者从同一长度开始向后遍历
	while (head1 != NULL)
	{
		if (head1->value == head2->value)     // 如果链表1的头与链表2头指向的数字一致，则返回此值，否则继续向后遍历
			return head1->value;
		head1 = head1->next;
		head2 = head2->next;
	}
	return NULL;
}



//另外不需要获取链表长度的做法
//假定 List1长度 : a + n  List2 长度 : b + n, 且 a < b
//	那么 p1 会先到链表尾部, 这时p2 走到 a + n位置, 将p1换成List2头部
//	接着p2 再走b + n - (n + a) = b - a 步到链表尾部, 这时p1也走到List2的b - a位置，还差a步就到可能的第一个公共节点。
//	将p2 换成 List1头部，p2走a步也到可能的第一个公共节点。如果恰好p1 == p2, 那么p1就是第一个公共节点。      
//	或者p1和p2一起走n步到达列表尾部，二者没有公共节点，退出循环。 同理a >= b.时间复杂度O(n + a + b)

//ListNode* FindFirstCommonNode(ListNode* head1, ListNode* head2) {
//	ListNode* p1 = head1;
//	ListNode* p2 = head2;
//	while (p1 != p2) {
//		if (p1 != NULL) p1 = p1->next;
//		if (p2 != NULL) p2 = p2->next;

//		if (p1 != p2) {
//			if (p1 == NULL) p1 = pHead2;
//			if (p2 == NULL) p2 = pHead1;
//		}
//	}
//	return p1;
//}



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

	ListNode* myList1 = NULL;
	ListNode* head1 = NULL;
	int listLength2;
	cout << "listLength2:";
	cin >> listLength2;
	cout << "Please input " << listLength2 << " numbers" << endl;
	for (int i = 0; i < listLength2; i++)
	{
		if (head1 == NULL)
		{
			int t;
			head1 = new ListNode;
			cin >> t;
			head1->value = t;
			head1->next = NULL;
			myList1 = head1;
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
	printList(myList1, "myList: ");
	int number = FirstCommonNode(myList, myList1);
	cout << number;

	//删除链表
	while (myList != NULL)
	{
		ListNode* tmp = myList;
		myList = myList->next;
		delete tmp;
	}
	while (myList1 != NULL)
	{
		ListNode* tmp = myList1;
		myList1 = myList1->next;
		delete tmp;
	}
}
