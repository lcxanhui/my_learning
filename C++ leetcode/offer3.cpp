/*****************************************************************************************************
 *         ��ָoffer��3��
 *��һ����ά�����У�ÿ��һά����ĳ�����ͬ����ÿһ�ж����մ����ҵ�����˳������ÿһ�ж�����
  ���ϵ��µ�����˳�����������һ������������������һ����ά�����һ���������ж��������Ƿ��и�������
 
 * Example:
 *
 * Input:  ��ά������к����Լ������е����� ������target
 * Output: 0����1

 * Explanation:
 *
 *
 * Note:
 * �����Ͻǻ������½ǽ��б������
 *
 *
 ******************************************************************************************************/


#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;


bool Find(int target, vector<vector<int> > array) {
	int rows = array.size();          //�������
	int columns = array[0].size();    //�������
	if (array.empty())           //�ж������Ƿ�Ϊ�գ���������
		return false;
	int row = 0, column = columns - 1;     //�����Ͻǽ��б���
	while (row < rows && column >= 0)
	{
		if (array[row][column] == target)
			return true;
		else if (array[row][column] > target)   //�Ƶ�����
			column--;
		else
			row++;
	}
	return false;                              //�βη���ֵ
}

int main()
{
	int m, n;
	cin >> m >> n;
	//�����Ƕ�ά����Ľ���
	vector<vector<int> > ivec(m, vector<int>(n));    //m X nά������
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			ivec[i][j] = i + j;
		}
	}
	//�����ʹ�ӡ��ά����
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
