/*****************************************************************************************************
 *         剑指offer第29题
 * 数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,
   2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。
 *
 * Input:   数组
 * Output:  出现次数最多的数
 *
 * Note: （两种解法都是O(n)）
 * 如果有符合条件的数字，则它出现的次数比其他所有数字出现的次数和还要多。在遍历数组时保存两个值：
   一是数组中一个数字，一是次数。遍历下一个数字时，若它与之前保存的数字相同，则次数加1，否则次数减1；
   若次数为0，则保存下一个数字，并将次数置为1。遍历结束后，所保存的数字即为所求。然后再判断它是否符合条件即可。
 *
 * 本次提供两种方法：
 方法1：先排序，排序的中间数即为result
 方法2：如果有符合条件的数字，则它出现的次数比其他所有数字出现的次数和还要多。在遍历数组时保存两个值：
   一是数组中一个数字，一是次数。遍历下一个数字时，若它与之前保存的数字相同，则次数加1，否则次数减1；
   若次数为0，则保存下一个数字，并将次数置为1。遍历结束后，所保存的数字即为所求。然后再判断它是否符合条件即可。
 * author: lcxanhui@163.com
 * time: 2019.5.12
 ******************************************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

int MoreThanHalfNum(vector<int> numbers) {
	int len = numbers.size();
	if (len <= 0)
		return 0;
	int num = numbers[0], count = 1;
	for (int i = 1; i < len; i++)
	{
		// 遍历每个元素，并记录次数；若与前一个元素相同，则次数加1，否则次数减1
		if (numbers[i] == num)
			count++;
		else
			count--;
		if (count < 0)
		{
			num = numbers[i];
			count = 1;
		}
	}
	// Verifying
	count = 0;
	for (int i = 0; i < len; i++)
	{
		if (numbers[i] == num)
			count++;
	}
	if (count * 2 > len)
		return num;
	return num;
}

int main()
{
	vector<int> numbers;
	numbers.push_back(1);
	numbers.push_back(2);
	numbers.push_back(3);
	numbers.push_back(5);
	numbers.push_back(2);
	numbers.push_back(2);
	int result = MoreThanHalfNum(numbers);
	return result;
}