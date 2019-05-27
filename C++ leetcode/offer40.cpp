/*****************************************************************************************************
 *         剑指offer第40题
 * 一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。
 *
 * Input:  一维数组
 * Output: 一维数组中只出现一次的两个数
 *
 * Note:(利用异或和位运算操作，将数组分为两部分)
 * 从头到尾依次异或数组中的每一个数字，那么最终得到的结果就是两个只出现一次的数字的异或结果。
   (因为其它数字都出现了两次，在异或中全部抵消掉了)。
   由于这两个数字肯定不一样，那么这个异或结果肯定不为0，也就是说在这个结果数字的二进制表示中至少就有一位为1。
   我们在结果数字中找到第一个为1的位的位置，记为第N位。现在我们以第N位是不是1为标准把原数组中的数字分成两个子数组，
   第一个子数组中每个数字的第N 位都为1，而第二个子数组的每个数字的第N 位都为0。
   现在我们已经把原数组分成了两个子数组，每个子数组都包含一个只出现一次的数字，而其它数字都出现了两次。
 * author: lcxanhui@163.com
 * time: 2019.5.27
 ******************************************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

// 判断在num的二进制表示中从右边数起第index个是否为1
bool isBit(int num, int index)
{
	num = num >> index;
	return (num & 1);
}

// 函数判断数字是否出现仅仅一次
void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
	int len = data.size();
	if (len < 2) // 如果数组长度小于2，返回空
		return;
	int temp = data[0];
	for (int i = 1; i < len; i++)
		temp = temp ^ data[i];    //将数组的每一个进行异或，最后的结果为两个不同数字的异或结果(相同为0，不同为1)
	                              //  其中结果中的二进制表示必定含有1（如果数组中有两个不同的数字）
	if (temp == 0)
		return;
	int index = 0;           //获取结果表示的二进制数字第一位为1最低位的具体为哪一位（与1进行与操作运算）
	while ((temp & 1) == 0)
	{
		temp = temp >> 1;
		index++;
	}	
	*num1 = *num2 = 0;
	for (int i = 0; i < len; i++)
	{
		if (isBit(data[i],index))    // 将数组进行分组，其中一组为二进制index位是1，另一组不为1，
			*num1 ^= data[i];        //再将两组进行异或，最终每组得到的结果为最终每组仅有的一个数
		else
			*num2 ^= data[i];
	}
}

int main()
{
	vector<int> data = { 1,2,2,3,4,5,3,5 };
	int result1, result2;
	FindNumsAppearOnce(data, &result1, &result2);
	cout << result1<<endl;
	cout << result2<<endl;
	return 0;
}