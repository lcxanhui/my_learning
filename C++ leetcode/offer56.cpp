/*****************************************************************************************************
 *         ��ָoffer��56��
 * ��һ�����������а����������ҳ�������Ļ�����ڽ�㣬�������null��
 *
 * Input:  ����
 * Output: ���������л����򷵻ػ�����ڽڵ�
 *
 *
 * Note: ������ָ����ͣ����Ծ�������
 * ������LeetCode 142�⣬�ܾ������Ŀ������Floyd�㷨����֤�����Ǳ���Ŀ����Ļ�����
 * ��˵Floyd��������ָ��һ��fast��һ��slowͬʱ��һ�������ͷ������
    fastһ����2����slowһ����һ��������������л�������ָ���Ȼ�ڻ�������
    ��ʱֻ��Ҫ�����е�һ��ָ������ָ������ͷ������һ�����䣨���ڻ��ڣ���
    �������ָ��һ����һ���������ĵط�������ڽڵ㡣

 * author: lcxanhui@163.com
 * time: 2019.6.29
 ******************************************************************************************************/

#include <iostream>
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

// �ҵ������е�һ������ʱ�Ľڵ�
ListNode* meetingNode(ListNode *head)
{
	if (head == NULL)
		return NULL;
	ListNode* fast = head;
	ListNode* slow = head;
	while (fast != NULL && fast->next != NULL)    //ע����ж�������while��if
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
			return fast;
	}
	return NULL;
}

//һ��ָ������ָ������ͷ��head,����һ��ָ�����������Ľڵ㣬��������������Ϊ���ջ������
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

	//ɾ������
	while (myList != NULL)
	{
		ListNode* tmp = myList;
		myList = myList->next;
		delete tmp;
	}
}