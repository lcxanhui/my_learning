/*****************************************************************************************************
 *         剑指offer第3题
 *在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照
  从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
 
 * Example:
 *
 * Input:  二维数组的行和列以及数组中的数， 再输入target
 * Output: 0或者1

 * Explanation:
 *
 *
 * Note:
 * 从左上角或者右下角进行遍历求解
 *
 *
 ******************************************************************************************************/


#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;


bool Find(int target, vector<vector<int> > array) {
	int rows = array.size();          //数组的行
	int columns = array[0].size();    //数组的列
	if (array.empty())           //判断数组是否为空，特殊条件
		return false;
	int row = 0, column = columns - 1;     //从左上角进行遍历
	while (row < rows && column >= 0)
	{
		if (array[row][column] == target)
			return true;
		else if (array[row][column] > target)   //推导条件
			column--;
		else
			row++;
	}
	return false;                              //形参返回值
}

int main()
{
	int m, n;
	cin >> m >> n;
	//下面是二维数组的建立
	vector<vector<int> > ivec(m, vector<int>(n));    //m X n维的数组
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			ivec[i][j] = i + j;
		}
	}
	//遍历和打印二维数组
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
		{
			cout << ivec[i][j] << " ";
		}
		cout << endl;
	}

	bool result =0;
	int target;
	cin >> target;
	result = Find(target, ivec);
	return result;
}
