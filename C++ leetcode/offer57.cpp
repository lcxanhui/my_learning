/*****************************************************************************************************
 *         ��ָoffer��57��
 * ��һ������������У������ظ��Ľ�㣬��ɾ�����������ظ��Ľ�㣬�ظ��Ľ�㲻��������������ͷָ�롣 
   ���磬����1->2->3->3->4->4->5 �����Ϊ 1->2->5
 *
 * Input:  ����
 * Output: ɾ���ظ����ݺ������
 *
 * Note: 
 * �ǵݹ�Ĵ��룺
   1. �������һ��ͷ�ڵ㣬�Է���������һ�����ڶ����ڵ����ͬ�����
   2.���� pre��last ָ�룬preָ��ָ��ǰȷ�����ظ����Ǹ��ڵ㣬��lastָ���൱�ڹ���ָ�룬һֱ������������
 * author: lcxanhui@163.com
 * time: 2019.6.30
 ******************************************************************************************************/

#include <iostream>
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

// ɾ�������������ͬ�Ľڵ�
ListNode* DelDuplication(ListNode *head)
{
	if (head == NULL||head->next==NULL)
		return head;
	ListNode* newhead = new ListNode(); //����ʱ��һ��trick,��ֹͷ���ͺ�һ���ڵ�Ҳ���ظ���
	newhead->next = head;
	ListNode* pre = newhead;
	ListNode* last = newhead->next;//��ֹhead�ڵ��������ظ������
	while (last->next != NULL)
	{
		if (last->next != NULL && last->value == last->next->value)
		{
			while (last->next != NULL && last->value == last->next->value)//��ǰ�ڵ�ͺ�һ���ڵ��ظ�����ָ�����Ľڵ�
			{
				last = last->next;
			}
			pre->next = last->next; //��ʱpre->nextָ��last->next,Ҳ���ǽ��ظ��Ľڵ�Ҳɾ��
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

	//ɾ������
	while (myList != NULL)
	{
		ListNode* tmp = myList;
		myList = myList->next;
		delete tmp;
	}
}