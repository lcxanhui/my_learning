/*****************************************************************************************************
 *                     剑指offer第66题
 * 请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的任意
   一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。如果一条路径经过了矩阵中的某一个
   格子，则之后不能再次进入这个格子。 例如 a b c e s f c s a d e e 这样的3 X 4 矩阵中包含一条字符串"bcced"
   的路径，但是矩阵中不包含"abcb"路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不
   能再次进入该格子。
 *
 * Input:  matrix以及路径
 * Output:0或1
 *
 * Note: （回溯法）
 *   还有八皇后问题也是经典的回溯法例题，大家可以参考;在《剑指offer》书中也给出了八皇后问题的思路；
     不过，那个是在全排列问题中引出来的。其实回溯法也是全排列的一种方案，在本题中，也就是尝试了
     matrix矩阵中所有点作为起点的方法，然后依据这个点进行向四个方向的递归；
     在递归中，不满足题目的会自动出栈回到上一个状态；

 * author: lcxanhui@163.com
 * time: 2019.7.14
 ******************************************************************************************************/


#include<iostream>
#include<string>
#include<stack>
using namespace std;

class Solution {
public:
	bool has(char* matrix, int rows, int cols, int i, int j, bool* flag, int k,const char* str)
	{
		//因为是一维数组存放二维的值，index值就是相当于二维数组的（i，j）在一维数组的下标
		int index = i * cols + j;
		//flag[index]==true,说明被访问过了，那么也返回true;
		if (i < 0 || i >= rows || j < 0 || j >= cols || matrix[index] != str[k] || flag[index] == true)
			return false;
		//字符串已经查找结束，说明找到该路径了
		if (str[k + 1] == '\0')
			return true;
		flag[index] = true;     //标记为被访问过
		//回溯法四个方向
		if (has(matrix, rows, cols, i + 1, j, flag, k + 1, str)
			|| has(matrix, rows, cols, i - 1, j, flag, k + 1, str)
			|| has(matrix, rows, cols, i, j + 1, flag, k + 1, str)
			|| has(matrix, rows, cols, i, j - 1, flag, k + 1, str))
			return true;
		flag[index] = false;
		return false;
	}
	bool hasPath(char* matrix, int rows, int cols, const char* str)
	{
		if (matrix==NULL || rows < 1 || cols < 1 || str==NULL)
			return false;
		//设置标志位，该标志意味着某字符是否已经被遍历到
		bool* flag = new bool[cols*rows];
		memset(flag, false, cols*rows);
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
			   //回溯法
				if (has(matrix, rows, cols, i, j, flag, 0, str))
					return true;
			}
		}
		//new调用构造函数，需要用delete的析构函数进行内存的释放
		delete[] flag;
		return false;
	}
};

int main(int argc, char* argv[])
{
	//测试用例
	//char matrix[] = "ABCESFCSADEE";
	//const char* str = "SEE";

	char matrix[] = "ABCESFCSADEE";
	const char* str = "ABCCED";

	int rows = 3, cols = 4;
	Solution s;
	bool res = s.hasPath(matrix, rows, cols, str);
	cout << res << endl;

	system("pause");
	return 0;

}