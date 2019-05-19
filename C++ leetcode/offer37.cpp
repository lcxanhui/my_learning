/*****************************************************************************************************
 *         ��ָoffer��37��
 * �������������ҳ����ǵĵ�һ��������㡣
 *
 * Input:  ������������ÿ���ڵ����
 * Output: ��������ĵ�һ���������
 *
 * Note: �����⻹������ͬ����˼·��ȡ����������͵Ĺ������ȣ�
 *  1. �ҳ�2������ĳ��ȣ�
    2.Ȼ���ó���������������ĳ��Ȳ
	3.Ȼ����һ���ߣ�ֱ����������ͬ��ֵ
  ����Ϊ2�������ù�����β����ʱ�临�Ӷ�O(mn)��

  �����ṩ�ķ�������Ҫ��ȡ����ĳ��ȣ������ڿ���ָ���˼·
 * author: lcxanhui@163.com
 * time: 2019.5.19
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

// ��ȡ����ĳ��ȣ����ں���Ƚ���������
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

// ���ڽϳ��������������������ֵ�ĳ���
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
	int len1 = GetLenOfList(head1);   //�ֱ��ȡ����1������2�ĳ���
	int len2 = GetLenOfList(head2);
	if (len2 > len1)
		head2 = walkstep(head2, len2 - len1);
	else
		head1 = walkstep(head1, len1 - len2);    //���ڽϳ����ȵ������������������ȵĲ�ֵ��ʹ�����ߴ�ͬһ���ȿ�ʼ������
	while (head1 != NULL)
	{
		if (head1->value == head2->value)     // �������1��ͷ������2ͷָ�������һ�£��򷵻ش�ֵ���������������
			return head1->value;
		head1 = head1->next;
		head2 = head2->next;
	}
	return NULL;
}



//���ⲻ��Ҫ��ȡ�����ȵ�����
//�ٶ� List1���� : a + n  List2 ���� : b + n, �� a < b
//	��ô p1 ���ȵ�����β��, ��ʱp2 �ߵ� a + nλ��, ��p1����List2ͷ��
//	����p2 ����b + n - (n + a) = b - a ��������β��, ��ʱp1Ҳ�ߵ�List2��b - aλ�ã�����a���͵����ܵĵ�һ�������ڵ㡣
//	��p2 ���� List1ͷ����p2��a��Ҳ�����ܵĵ�һ�������ڵ㡣���ǡ��p1 == p2, ��ôp1���ǵ�һ�������ڵ㡣      
//	����p1��p2һ����n�������б�β��������û�й����ڵ㣬�˳�ѭ���� ͬ��a >= b.ʱ�临�Ӷ�O(n + a + b)

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

	//ɾ������
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
