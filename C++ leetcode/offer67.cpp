/*****************************************************************************************************
 *                     ��ָoffer��67��
 * ������һ��m�к�n�еķ���һ�������˴�����0,0�ĸ��ӿ�ʼ�ƶ���ÿһ��ֻ�������ң��ϣ����ĸ������ƶ�
   һ�񣬵��ǲ��ܽ�������������������λ֮�ʹ���k�ĸ��ӡ� ���磬��kΪ18ʱ���������ܹ����뷽��35,37����
   ��Ϊ3+5+3+7 = 18�����ǣ������ܽ��뷽��35,38������Ϊ3+5+3+8 = 19�����ʸû������ܹ��ﵽ���ٸ����ӣ�
 *
 * Input:  ��ֵ�Լ����������
 * Output: �������ܹ�����ĸ�����
 *
 * Note: �����ݷ����ٴ�Ӧ�ã�
 *   ������ȡ���е����ֱ��ͼ�getSum��Ȼ���������������û��ݷ������ƶ��������ֱ����������½����ƶ���Ȼ������flag
    ��¼�����Ƿ��߹����߹�Ϊtrue��û���߹�Ϊfalse,���շ��ؼ������
 * author: lcxanhui@163.com
 * time: 2019.7.15
 ******************************************************************************************************/


#include<iostream>
#include<string>
#include<stack>
using namespace std;

class Solution {
public:
	// ����ÿ���ո�λ�õ����ֺ�
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
	//�߽�����
	bool check(int threshold, int rows, int cols, int i, int j, bool* flag)
	{
		if (i >= 0 && i < rows && j >= 0 && j < cols &&
			getSum(i) + getSum(j) <= threshold && flag[i*cols + j] == false)
			return true;
		return false;
	}
	int moving(int threshold, int rows, int cols, int i, int j, bool* flag)
	{
		//��Ϊ��һά�����Ŷ�ά��ֵ��indexֵ�����൱�ڶ�ά����ģ�i��j����һά������±�
		int index = i * cols + j;
		int count = 0;
		if (check(threshold, rows, cols, i,j,flag))   //�߽�����Ϊ��
		{ 
			flag[index] = true;     // �ø�������Ϊ�Ѿ��߹�
			//���û��ݷ��������������ƶ��ļ������
			count = 1 + moving(threshold, rows, cols, i + 1, j, flag)
				+ moving(threshold, rows, cols, i - 1, j, flag)
				+ moving(threshold, rows, cols, i, j + 1, flag)
				+ moving(threshold, rows, cols, i, j - 1, flag);
		}
		return count;
	}
	int hasPath(int threshold, int rows, int cols)
	{
		//���ñ�־λ���ñ�־��ζ��ĳ�ַ��Ƿ��Ѿ���������
		bool* flag = new bool[cols*rows];
		memset(flag, false, cols*rows);
		//��̬�滮����dfs
		int count = moving(threshold, rows, cols,0,0, flag);
		//new���ù��캯������Ҫ��delete���������������ڴ���ͷ�
		delete[] flag;
		return count;
	}
};

int main(int argc, char* argv[])
{
	//�������� 
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