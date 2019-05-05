/*****************************************************************************************************
 *         ��ָoffer��20��
 * ����һ�����󣬰��մ���������˳ʱ���˳�����δ�ӡ��ÿһ�����֣����磬�����������4 X 4���� 
   1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 �����δ�ӡ������1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
 *
 * Input:  ��ά����
 * Output: ����������˳ʱ���ӡ��һά����
 *
 * Note: �����ͼ�����Ƚ�ֱ�ۣ�
 * ÿһȦ����������Ǵӣ�i��i����ʼ������ÿһȦ�����Ĳ���ɣ������ͣ������е�һ��һ�����ڣ��ڶ�����
   ���͵��Ĳ�����������Ҫ���������ж�
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
		for (int i = 0; i <= right; i++)   //�����ҵ�һ����һȦ����ʼһ������
			res.push_back(matrix[top][i]);
		for (int i = top+1; i <= bottom; i++)   //���ϵ��µڶ���
			res.push_back(matrix[i][right]);
		if (top != bottom)            //���ҵ��������
			for (int i = right - 1; i >= left; i--)  res.push_back(matrix[bottom][i]);
		if (left != right)            // ���µ��ϵ��Ĳ�
			for (int i = bottom - 1; i >= top + 1; i--)  res.push_back(matrix[i][left]);
	}
	return res;
}

int main()
{
	vector<vector<int>> arr;  //����Ҳ����ֱ�Ӷ��������ĳߴ�
	//��ʼ��
	int row,column;
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
			//Ҳ����������ķ�ʽֱ�����룬arr[m][n] = m+n�����Ե���m+n��Ҳ���Ե�����������
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
	vector<int> res;
	res = PrintInCircle(arr);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	return 0;
}