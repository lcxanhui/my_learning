/*****************************************************************************************************
 *                     ��ָoffer��66��
 * �����һ�������������ж���һ���������Ƿ����һ������ĳ�ַ��������ַ���·����·�����ԴӾ����е�����
   һ�����ӿ�ʼ��ÿһ�������ھ������������ң����ϣ������ƶ�һ�����ӡ����һ��·�������˾����е�ĳһ��
   ���ӣ���֮�����ٴν���������ӡ� ���� a b c e s f c s a d e e ������3 X 4 �����а���һ���ַ���"bcced"
   ��·�������Ǿ����в�����"abcb"·������Ϊ�ַ����ĵ�һ���ַ�bռ���˾����еĵ�һ�еڶ�������֮��·����
   ���ٴν���ø��ӡ�
 *
 * Input:  matrix�Լ�·��
 * Output:0��1
 *
 * Note: �����ݷ���
 *   ���а˻ʺ�����Ҳ�Ǿ���Ļ��ݷ����⣬��ҿ��Բο�;�ڡ���ָoffer������Ҳ�����˰˻ʺ������˼·��
     �������Ǹ�����ȫ�����������������ġ���ʵ���ݷ�Ҳ��ȫ���е�һ�ַ������ڱ����У�Ҳ���ǳ�����
     matrix���������е���Ϊ���ķ�����Ȼ�����������������ĸ�����ĵݹ飻
     �ڵݹ��У���������Ŀ�Ļ��Զ���ջ�ص���һ��״̬��

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
		//��Ϊ��һά�����Ŷ�ά��ֵ��indexֵ�����൱�ڶ�ά����ģ�i��j����һά������±�
		int index = i * cols + j;
		//flag[index]==true,˵�������ʹ��ˣ���ôҲ����true;
		if (i < 0 || i >= rows || j < 0 || j >= cols || matrix[index] != str[k] || flag[index] == true)
			return false;
		//�ַ����Ѿ����ҽ�����˵���ҵ���·����
		if (str[k + 1] == '\0')
			return true;
		flag[index] = true;     //���Ϊ�����ʹ�
		//���ݷ��ĸ�����
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
		//���ñ�־λ���ñ�־��ζ��ĳ�ַ��Ƿ��Ѿ���������
		bool* flag = new bool[cols*rows];
		memset(flag, false, cols*rows);
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
			   //���ݷ�
				if (has(matrix, rows, cols, i, j, flag, 0, str))
					return true;
			}
		}
		//new���ù��캯������Ҫ��delete���������������ڴ���ͷ�
		delete[] flag;
		return false;
	}
};

int main(int argc, char* argv[])
{
	//��������
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