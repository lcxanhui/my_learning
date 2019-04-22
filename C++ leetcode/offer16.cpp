/*****************************************************************************************************
 *         ��ָoffer��16��
 * ����һ��������ת��������������ı�ͷ��
 *
 * Input:  ��������ĳ����Լ�ÿ���ڵ����
 * Output: ��ת��ĵ�������
 *
 *
 * Note: �����ͼ�����Ƚ�ֱ�ۣ�
 * �������������Ĵ������

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

ListNode* ReverseList(ListNode* Head)
{
	if (Head == NULL)
		return NULL;        //headΪ��ǰ�ڵ㣬�����ǰ�ڵ�Ϊ�յĻ����Ǿ�ʲôҲ������ֱ�ӷ���NULL��
	
	ListNode* Pre = NULL; 
	ListNode* Next = NULL;
	//��ǰ�ڵ���head��preΪ��ǰ�ڵ��ǰһ�ڵ㣬nextΪ��ǰ�ڵ����һ�ڵ�,��Ҫpre��next��Ŀ����
	//�õ�ǰ�ڵ��pre->head->next1->next2���pre<-head next1->next2
	//��pre�ýڵ���Է�ת��ָ���򣬵���ת֮���������next�ڵ㱣��next1�ڵ�Ļ����˵�����ʹ˶Ͽ���
	//������Ҫ�õ�pre��next�����ڵ�

	while (Head != NULL) //��ѭ������ǰ�ڵ㲻Ϊ�յĻ���ʼ��ִ�д�ѭ������ѭ����Ŀ�ľ����õ�ǰ�ڵ��ָ��next��ָ��pre
	{
		//��˾Ϳ���������ת�����Ч��
		//����next����head����һ���ڵ����Ϣ����֤����������Ϊʧȥhead�ڵ��ԭnext�ڵ���ʹ˶���
		Next = Head->next;   
		//������next���Ϳ�����head��ָ��next���ָ��pre��
		Head->next = Pre;

		//headָ��pre�󣬾ͼ������η�ת��һ���ڵ�
		//��pre��head��next��������ƶ�һ���ڵ㣬������һ�ε�ָ�뷴ת
		Pre = Head;
		Head = Next;
	}
	//���headΪnull��ʱ��pre��Ϊ���һ���ڵ��ˣ����������Ѿ���ת��ϣ�pre���Ƿ�ת������ĵ�һ���ڵ�
	//ֱ�����pre����������Ҫ�õ��ķ�ת�������
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

	//ɾ������
	while (myList != NULL)
	{
		ListNode* tmp = myList;
		myList = myList->next;
		delete tmp;
	}
}