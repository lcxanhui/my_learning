/*****************************************************************************************************
 *         ��ָoffer��5��
 * ����һ������������ֵ��β��ͷ��˳�򷵻�һ��ArrayList����
 *
 * Input:  ��������ĳ����Լ�ÿ���ڵ����
 * Output: ��������Ĵ�β��ͷ
 *
 *
 * Note: (�ݹ�˼��)
 * �ݹ��ӡ���ɣ���������ܴ�Ļ����ݹ��ľ�ջ�ռ䣬������û���ʹ�ö�����ڴ��Լ�ά��һ��ջ��
 * authur: lcxanhui@163.com 
 * time: 2019.4.17
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

void printListInReversedOrder(ListNode* head)
{
	if (head == NULL)
		return;
	if (head->next == NULL)
	{
		cout << head->value << "->";
		return;
	}
	//�ȴ�ӡ����ģ��ڴ�ӡ��ǰ�ڵ�	
	printListInReversedOrder(head->next);        //���ṹ���÷������ݹ����˼��
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

	//ɾ������
	while (myList != NULL)
	{
		ListNode* tmp = myList;
		myList = myList->next;
		delete tmp;
	}
}