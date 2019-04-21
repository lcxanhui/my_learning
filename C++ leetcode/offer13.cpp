/*****************************************************************************************************
 *         剑指offer第5题
 * 给定链表的头指针和一个结点指针，定义一个函数在在O(1)时间删除该结点。
 *
 * Input:  单向链表的长度以及每个节点的数和要删除的节点
 * Output: 删除后的单向链表
 *
 *
 * Note: (乾坤大挪移---时间复杂度)
 * 这是一道广为流传的Google面试题，能有效考察我们的编程基本功，还能考察我们的反应速度，更重要的是，还能
   考察我们对时间复杂度的理解。在链表中删除一个结点，最常规的做法是从链表的头结点开始，顺序查找要删除的
   结点，找到之后再删除。由于需要顺序查找，时间复杂度自然就是O(n)了。 我们之所以需要从头结点开始查找要
   删除的结点，是因为我们需要得到要删除的结点的前面一个结点。我们试着换一种思路。

   我们可以从给定的结点得到它的下一个结点。这个时候我们实际能够删除的是它的下一个结点，由于我们已经得到
   实际删除的结点的前面一个结点，因此完全是可以实现的。当然，在删除之前，我们需要需要把给定的结点的下一
   个结点的数据拷贝到给定的结点中。此时，时间复杂度为O(1)。
   上面的思路还有一个问题：如果删除的结点位于链表的尾部，没有下一个结点，怎么办？
   我们仍然从链表的头结点开始，顺便遍历得到给定结点的前序结点，并完成删除操作。这个时候时间复杂度是O(n)。
   只有当给定的结点处于链表末尾的时候，时间复杂度为O(n)。那么平均时间复杂度[(n-1)*O(1)+O(n)]/n，仍然为O(1)。
 * author: lcxanhui@163.com
 * time: 2019.4.21
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

void DeleteNode(ListNode* Listhead, ListNode* TobeDelete)
{
	if (Listhead == NULL || TobeDelete == NULL)
		return;
	if (TobeDelete->next != NULL)        //如果要删除的节点的下一位不位NULL,即不是尾结点，则将下一节点的值复制到要		                                   
	{                                    //删除的结点，指向下一节点的节点，并将下一节点删除
		ListNode* tmp = TobeDelete->next;
		TobeDelete->value = tmp->value;
		TobeDelete->next = tmp->next;

		delete tmp;                    //删除下一节点
		tmp = NULL;
	}
	else if (Listhead == TobeDelete)         //特殊情况：当链表只有一个节点并且为要删除的节点
	{
		delete TobeDelete;
		TobeDelete = NULL;
		Listhead = NULL;
	}
	else                                //尾结点的情况，必须要顺序遍历，时间复杂度为O(n)
	{
		ListNode* Node = Listhead;
		while(Node->next != TobeDelete)
		{
			Node = Node->next;
		}
		Node->next = NULL;
		delete TobeDelete;               //将要删除节点设置为NULL，并删除要删除的节点
		TobeDelete = NULL;
	}
}

int main()
{
	ListNode* myList = NULL;
	ListNode* head = NULL;
	ListNode* TobeDelete = NULL;
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
		if (i == listLength - 1)
			TobeDelete = head;
	}
	printList(myList, "myList: ");
	cout << "To be deleted: " << TobeDelete->value<<endl;
	DeleteNode(myList,TobeDelete);
	printList(myList, "After deeation: ");

	//删除链表
	while (myList != NULL)
	{
		ListNode* tmp = myList;
		myList = myList->next;
		delete tmp;
	}
}