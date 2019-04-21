/*****************************************************************************************************
 *         ��ָoffer��5��
 * ���������ͷָ���һ�����ָ�룬����һ����������O(1)ʱ��ɾ���ý�㡣
 *
 * Input:  ��������ĳ����Լ�ÿ���ڵ������Ҫɾ���Ľڵ�
 * Output: ɾ����ĵ�������
 *
 *
 * Note: (Ǭ����Ų��---ʱ�临�Ӷ�)
 * ����һ����Ϊ������Google�����⣬����Ч�������ǵı�̻����������ܿ������ǵķ�Ӧ�ٶȣ�����Ҫ���ǣ�����
   �������Ƕ�ʱ�临�Ӷȵ���⡣��������ɾ��һ����㣬���������Ǵ������ͷ��㿪ʼ��˳�����Ҫɾ����
   ��㣬�ҵ�֮����ɾ����������Ҫ˳����ң�ʱ�临�Ӷ���Ȼ����O(n)�ˡ� ����֮������Ҫ��ͷ��㿪ʼ����Ҫ
   ɾ���Ľ�㣬����Ϊ������Ҫ�õ�Ҫɾ���Ľ���ǰ��һ����㡣�������Ż�һ��˼·��

   ���ǿ��ԴӸ����Ľ��õ�������һ����㡣���ʱ������ʵ���ܹ�ɾ������������һ����㣬���������Ѿ��õ�
   ʵ��ɾ���Ľ���ǰ��һ����㣬�����ȫ�ǿ���ʵ�ֵġ���Ȼ����ɾ��֮ǰ��������Ҫ��Ҫ�Ѹ����Ľ�����һ
   ���������ݿ����������Ľ���С���ʱ��ʱ�临�Ӷ�ΪO(1)��
   �����˼·����һ�����⣺���ɾ���Ľ��λ�������β����û����һ����㣬��ô�죿
   ������Ȼ�������ͷ��㿪ʼ��˳������õ���������ǰ���㣬�����ɾ�����������ʱ��ʱ�临�Ӷ���O(n)��
   ֻ�е������Ľ�㴦������ĩβ��ʱ��ʱ�临�Ӷ�ΪO(n)����ôƽ��ʱ�临�Ӷ�[(n-1)*O(1)+O(n)]/n����ȻΪO(1)��
 * author: lcxanhui@163.com
 * time: 2019.4.21
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

void DeleteNode(ListNode* Listhead, ListNode* TobeDelete)
{
	if (Listhead == NULL || TobeDelete == NULL)
		return;
	if (TobeDelete->next != NULL)        //���Ҫɾ���Ľڵ����һλ��λNULL,������β��㣬����һ�ڵ��ֵ���Ƶ�Ҫ		                                   
	{                                    //ɾ���Ľ�㣬ָ����һ�ڵ�Ľڵ㣬������һ�ڵ�ɾ��
		ListNode* tmp = TobeDelete->next;
		TobeDelete->value = tmp->value;
		TobeDelete->next = tmp->next;

		delete tmp;                    //ɾ����һ�ڵ�
		tmp = NULL;
	}
	else if (Listhead == TobeDelete)         //���������������ֻ��һ���ڵ㲢��ΪҪɾ���Ľڵ�
	{
		delete TobeDelete;
		TobeDelete = NULL;
		Listhead = NULL;
	}
	else                                //β�������������Ҫ˳�������ʱ�临�Ӷ�ΪO(n)
	{
		ListNode* Node = Listhead;
		while(Node->next != TobeDelete)
		{
			Node = Node->next;
		}
		Node->next = NULL;
		delete TobeDelete;               //��Ҫɾ���ڵ�����ΪNULL����ɾ��Ҫɾ���Ľڵ�
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

	//ɾ������
	while (myList != NULL)
	{
		ListNode* tmp = myList;
		myList = myList->next;
		delete tmp;
	}
}