/*****************************************************************************************************
 *                      剑指offer第51题
 * 在一个长度为n的数组里的所有数字都在0到n-1的范围内。 数组中某些数字是重复的，但不知道有几个数字是
   重复的。也不知道每个数字重复几次。请找出数组中任意一个重复的数字。 例如，如果输入长度为7的数组
   {2,3,1,0,2,5,3}，那么对应的输出是第一个重复的数字2。
 *
 * Input:  数组
 * Output: 数组中重复的数字
 *
 * Note:
   1、判断输入数组有无元素非法
   2、从头扫到尾，只要当前元素值与下标不同，就做一次判断,numbers[i]与numbers[numbers[i]]，相等就认为找到了
	  重复元素，返回true,否则就交换两者，继续循环。直到最后还没找到认为没找到重复元素，返回false

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
			while (numbers[i] != i)  // 当数组的第i个数字指向的数字不为当前对应的下标时，分两种情况，如果
									 // 当前第i个数字指向的数字与第i个数字指向的数字的数字相等则存在重复，否则交换
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


//利用hashtable进行求解
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
		int hashTable[255] = { 0 };     // 建立hashtable
		for (int i = 0; i < length; i++)
		{
			hashTable[numbers[i]]++;    // 遍历数组，查询每个数字出现的次数
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
	cout << "重复出现的数字为：" << endl;
	cout << *duplication << endl;
	delete duplication;

	system("pause");
	return 0;
}