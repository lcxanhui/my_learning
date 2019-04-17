/*****************************************************************************************************
 *         ��ָoffer��15��
 *����һ����������������е�����k����㡣
 *
 * Input:  ��������ĳ����Լ�ÿ���ڵ����
 * Output: ������������k���ڵ����
 *
 *
 * Note:(����ָ��)
 * �����ǵ��������ǲ�֪��������n����Ȼ������ȫ����ֻ�ߣ�n-k��������򵥵Ļ�ȡ�����ȵķ�������
 * ����һ������Ȼ���ٴ�ͷ��ʼ�ߣ�n-k�������������Ľ�������࣬����һ�ֺܺõķ�����������������
 * ��Ľ������ܶ࣬�п��ܲ���һ���԰�����������Ӳ�̶��������ڴ棬��ô����������ζ��һ�������Ҫ
 * ���δ�Ӳ�̶��뵽�����ڴ档����֪�������ݴ�Ӳ�̶��뵽�ڴ��Ƿǳ���ʱ��Ĳ����������ܲ��ܰ��������
 * �Ĵ������ٵ�1��������ԣ�������Ч����ߴ���ִ�е�ʱ��Ч�ʡ���������ڱ���ʱά������ָ�룬��һ��
 * ָ��������ͷָ�뿪ʼ�������ڵ�k-1��֮ǰ���ڶ���ָ�뱣�ֲ������ڵ�k-1����ʼ���ڶ���ָ��Ҳ��ʼ��
 * �����ͷָ�뿪ʼ��������������ָ��ľ��뱣����k-1������һ��������ǰ��ģ�ָ�뵽�������β���ʱ��
 * �ڶ���ָ�루���ں���ģ�ָ�������ǵ�����k����㡣����˼·ֻ��Ҫ��������һ�Ρ����ںܳ�������ֻ��
 * Ҫ��ÿ������Ӳ�̵��뵽�ڴ�һ�Ρ������һ������ʱ��Ч��ǰ��ķ���Ҫ�ߡ�
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

//Ѱ����������K��Ԫ��
ListNode* FindkthToEnd(ListNode *myList, unsigned int k)
{
	//k ����������1����Ϊ��������һ�������NULL�����������жϣ�
	if ((myList == NULL) || (k <= 0))
	{
		cout << "myList is NULL or k <= 0." << endl;
		return NULL;
	}
	//����ָ��ı��֣��Ⱥ�ָ��
	ListNode* first = myList;
	ListNode* second = myList;
	// ��firstָ������k��
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
	// first and secondָ�붼�ߣ���secondָ�뵽����β��ʱ��firstָ��ָ�ľ��ǵ�����k�����
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
	//ɾ������
	while (myList != NULL)
	{
		ListNode* tmp = myList;
		myList = myList->next;
		delete tmp;
	}
}
