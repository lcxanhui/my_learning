/*****************************************************************************************************
 *         剑指offer第14题
 * 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数
   位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。。
 *
 * Input:   一个数组的长度和数组的数
 * Output:  数组按照奇偶数排序输出
 *
 * Note: （双指针法、插入排序等都可以解决本题）
 * 将数组进行遍历，将遍历的奇数依次保存到新的数组，然后将遍历的偶数保存到同一个新的数组，
   将得到的数组赋值给原来的数组；
 *
 * author: lcxanhui@163.com
 * time: 2019.4.21
 ******************************************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

void Reorder(vector<int> &array)
{
	int length = array.size();
	if (length == 0 || array.empty())
		return;
	vector<int> res;
	for (int i = 0; i < length; i++)     
	{
		if ((array[i] & 0x1) == 1)        //遍历所有的数，奇数情况下，保存到新的res
			res.push_back(array[i]);
	}
	for (int i = 0; i < length; i++)
	{
		if ((array[i] & 0x1) == 0)        //遍历所有的数，偶数情况下，保存到新的res
			res.push_back(array[i]);
	}
	array = res;
}

int main(void)
{
	int n, tmp;
	vector<int> arr;
	cin >> n;
	int i = n;
	while (n--)
	{
		cin >> tmp;
		arr.push_back(tmp);
	}

	Reorder(arr);
	for (int j = 0; j < i; j++)
		cout << arr[j] << " ";
	cout << endl;
	return 0;

}