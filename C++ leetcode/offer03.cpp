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
 * Note:
 * �����Ͻǻ������½ǽ��б������
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
	vector<vector<int>> arr;  //����Ҳ����ֱ�Ӷ��������ĳߴ�
	//��ʼ��
	int row, column;
	cout << "�����������������������";
	cin >> row >> column;
	//�����Ǹ���������洢�ռ�
	arr.resize(row);
	for (int i = 0; i < row; i++)
	{
		arr[i].resize(column);
	}
	//����Ԫ��
	cout << "����������Ԫ�أ�" << endl;
	for (int m = 0; m < row; m++)
	{
		for (int n = 0; n < column; n++)
		{
			cin >> arr[m][n]; //����cin���������һ��������
		}
	}
	//��ӡ����
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

