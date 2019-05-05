/*****************************************************************************************************
 *         剑指offer第20题
 * 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，例如，如果输入如下4 X 4矩阵： 
   1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
 *
 * Input:  二维矩阵
 * Output: 从外向里以顺时针打印的一维矩阵
 *
 * Note: （结合图分析比较直观）
 * 每一圈输出矩阵总是从（i，i）开始，并且每一圈都有四步组成（口字型），其中第一步一定存在，第二、第
   三和第四步骤存在与否需要条件进行判断
 * author: lcxanhui@163.com
 * time: 2019.5.5
 ******************************************************************************************************/

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

vector<int> PrintInCircle(vector<vector<int> > matrix)
{
	int row = matrix.size();
	int col = matrix[0].size();
	vector<int> res;
	res.clear();
	if (row==0 || col==0)
		return res;
	int left = 0, top = 0;
	int right = col - 1, bottom = col - 1;
	while (left<=right && top<=bottom)
	{
		for (int i = 0; i <= right; i++)   //从左到右第一步，一圈的起始一定存在
			res.push_back(matrix[top][i]);
		for (int i = top+1; i <= bottom; i++)   //从上到下第二步
			res.push_back(matrix[i][right]);
		if (top != bottom)            //从右到左第三步
			for (int i = right - 1; i >= left; i--)  res.push_back(matrix[bottom][i]);
		if (left != right)            // 从下到上第四步
			for (int i = bottom - 1; i >= top + 1; i--)  res.push_back(matrix[i][left]);
	}
	return res;
}

int main()
{
	vector<vector<int>> arr;  //这里也可以直接定义向量的尺寸
	//初始化
	int row,column;
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
			//也可以是下面的方式直接输入，arr[m][n] = m+n，可以等于m+n，也可以等于其他数字
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
	vector<int> res;
	res = PrintInCircle(arr);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	return 0;
}