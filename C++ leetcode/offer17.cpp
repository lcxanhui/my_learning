/*****************************************************************************************************
 *         ��ָoffer��16��
 * ���������������������������������ϳɺ��������Ȼ������Ҫ�ϳɺ���������㵥����������
 *
 * Input:  ������������ĳ����Լ�ÿ���ڵ����������������
 * Output: �ϲ��������
 *
 *
 * Note: �����ͼ�����Ƚ�ֱ�ۣ�
 * ��Ϊ�򵥵ĵݹ��㷨�����Ǹ��ӶȽϸߣ����Կ��������㷨
 * author: lcxanhui@163.com
 * time: 2019.4.22
 ******************************************************************************************************/

#include<iostream>
#include<stack>
#include<string>
using namespace std;

//��������ṹ
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

//��ӡ����
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
{    //head1Ϊ��ǰ�ڵ㣬�����ǰ�ڵ�Ϊ�յĻ����Ǿ�ʲôҲ������ֱ�ӷ���head2��ͬ��head2��
	if (Head1 == NULL)
		return Head2; 
	else if (Head2 == NULL)
		return Head1; 
	
	ListNode* MergeHead = NULL;
	if (Head1->value < Head2->value)
	{
		MergeHead = Head1;
		MergeHead->next=Merge(Head1->next,Head2);   //�ݹ��㷨
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

	//ɾ������
	//deleteList(myList1);
	//deleteList(myList2);
}