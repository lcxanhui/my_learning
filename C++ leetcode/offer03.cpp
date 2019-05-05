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
 * Note:
 * 从左上角或者右下角进行遍历求解
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
	vector<vector<int>> arr;  //这里也可以直接定义向量的尺寸
	//初始化
	int row, column;
	cout << "请输入数组的行数和列数：";
	cin >> row >> column;
	//下面是给向量分配存储空间
	arr.resize(row);
	for (int i = 0; i < row; i++)
	{
		arr[i].resize(column);
	}
	//存入元素
	cout << "请输入数组元素：" << endl;
	for (int m = 0; m < row; m++)
	{
		for (int n = 0; n < column; n++)
		{
			cin >> arr[m][n]; //利用cin在命令框中一个个输入
		}
	}
	//打印数组
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	bool result = 0;
	int target;
	cin >> target;
	result = Find(target, arr);
	return result;
}

