/*****************************************************************************************************
 *                      ��ָoffer��51��
 * ��һ������Ϊn����������������ֶ���0��n-1�ķ�Χ�ڡ� ������ĳЩ�������ظ��ģ�����֪���м���������
   �ظ��ġ�Ҳ��֪��ÿ�������ظ����Ρ����ҳ�����������һ���ظ������֡� ���磬������볤��Ϊ7������
   {2,3,1,0,2,5,3}����ô��Ӧ������ǵ�һ���ظ�������2��
 *
 * Input:  ����
 * Output: �������ظ�������
 *
 * Note:
   1���ж�������������Ԫ�طǷ�
   2����ͷɨ��β��ֻҪ��ǰԪ��ֵ���±겻ͬ������һ���ж�,numbers[i]��numbers[numbers[i]]����Ⱦ���Ϊ�ҵ���
	  �ظ�Ԫ�أ�����true,����ͽ������ߣ�����ѭ����ֱ�����û�ҵ���Ϊû�ҵ��ظ�Ԫ�أ�����false

 * author: lcxanhui@163.com
 * time: 2019.6.25
 ******************************************************************************************************/

#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:
	bool duplicate(int numbers[], int length, int* duplication) {
		if (numbers == NULL || length < 0)
			return false;
		for (int i = 0; i < length; i++)
		{
			if (numbers[i]<0 || numbers[i]>length - 1)
				return false;
		}
		for (int i = 0; i < length; i++)
		{
			while (numbers[i] != i)  // ������ĵ�i������ָ������ֲ�Ϊ��ǰ��Ӧ���±�ʱ����������������
									 // ��ǰ��i������ָ����������i������ָ������ֵ��������������ظ������򽻻�
			{
				if (numbers[i] == numbers[numbers[i]])
				{
					*duplication = numbers[i];
					return true;
				}
				swap(numbers[i], numbers[numbers[i]]);
			}
		}
		return false;
	}
};


//����hashtable�������
class Solution2 {
public:
	// Parameters:
	//        numbers:     an array of integers
	//        length:      the length of array numbers
	//        duplication: (Output) the duplicated number in the array number
	// Return value:       true if the input is valid, and there are some duplications in the array number
	//                     otherwise false
	bool duplicate(int numbers[], int length, int* duplication) {
		if (numbers == NULL || length == 0) return 0;
		int hashTable[255] = { 0 };     // ����hashtable
		for (int i = 0; i < length; i++)
		{
			hashTable[numbers[i]]++;    // �������飬��ѯÿ�����ֳ��ֵĴ���
		}
		int count = 0;
		for (int i = 0; i < length; i++)
		{
			if (hashTable[numbers[i]] > 1)
			{
				duplication[count++] = numbers[i];
				//break;
				return true;
			}
		}
		return false;
	}
};

int main()
{
	int array[] = { 2, 3, 1, 0, 2, 5, 3 };
	int length = sizeof(array) / sizeof(array[0]);
	Solution s;
	int *duplication = nullptr;
	duplication = new int(0);
	s.duplicate(array, length, duplication);
	cout << "�ظ����ֵ�����Ϊ��" << endl;
	cout << *duplication << endl;
	delete duplication;

	system("pause");
	return 0;
}