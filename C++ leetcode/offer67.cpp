/*****************************************************************************************************
 *                     剑指offer第67题
 * 地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，每一次只能向左，右，上，下四个方向移动
   一格，但是不能进入行坐标和列坐标的数位之和大于k的格子。 例如，当k为18时，机器人能够进入方格（35,37），
   因为3+5+3+7 = 18。但是，它不能进入方格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？
 *
 * Input:  阈值以及矩阵的行列
 * Output: 机器人能够到达的格子数
 *
 * Note: （回溯法的再次应用）
 *   首先求取行列的数字表达和即getSum，然后按照限制条件利用回溯法进行移动计数，分别是左右上下进行移动，然后利用flag
    记录格子是否走过，走过为true，没有走过为false,最终返回计数结果
 * author: lcxanhui@163.com
 * time: 2019.7.15
 ******************************************************************************************************/


#include<iostream>
#include<string>
#include<stack>
using namespace std;

class Solution {
public:
	// 计算每个空格位置的数字和
	int getSum(int num)
	{
		int sum = 0;
		while (num > 0)
		{
			sum += num % 10;
			num /= 10;
		}
		return sum;
	}
	//边界条件
	bool check(int threshold, int rows, int cols, int i, int j, bool* flag)
	{
		if (i >= 0 && i < rows && j >= 0 && j < cols &&
			getSum(i) + getSum(j) <= threshold && flag[i*cols + j] == false)
			return true;
		return false;
	}
	int moving(int threshold, int rows, int cols, int i, int j, bool* flag)
	{
		//因为是一维数组存放二维的值，index值就是相当于二维数组的（i，j）在一维数组的下标
		int index = i * cols + j;
		int count = 0;
		if (check(threshold, rows, cols, i,j,flag))   //边界条件为真
		{ 
			flag[index] = true;     // 该格子设置为已经走过
			//利用回溯法计算上下左右移动的计数结果
			count = 1 + moving(threshold, rows, cols, i + 1, j, flag)
				+ moving(threshold, rows, cols, i - 1, j, flag)
				+ moving(threshold, rows, cols, i, j + 1, flag)
				+ moving(threshold, rows, cols, i, j - 1, flag);
		}
		return count;
	}
	int hasPath(int threshold, int rows, int cols)
	{
		//设置标志位，该标志意味着某字符是否已经被遍历到
		bool* flag = new bool[cols*rows];
		memset(flag, false, cols*rows);
		//动态规划问题dfs
		int count = moving(threshold, rows, cols,0,0, flag);
		//new调用构造函数，需要用delete的析构函数进行内存的释放
		delete[] flag;
		return count;
	}
};

int main(int argc, char* argv[])
{
	//测试用例 
	// 5,10,10    21
	// 15,20,20    359
	// 15,1,1      1
	// -10,10,10   0

	int threshold = 10;
	int rows = 1, cols = 100;
	Solution s;
	int count = s.hasPath(threshold, rows, cols);
	cout << count << endl;

	system("pause");
	return 0;
}