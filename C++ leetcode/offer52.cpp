/*****************************************************************************************************
 *              ��ָoffer��52��
 * ����һ������A[0,1,...,n-1],�빹��һ������B[0,1,...,n-1],����B�е�Ԫ��B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]
   *...*A[n-1]������ʹ�ó�����
 *
 * Input:  ����A[0,1,...,n-1]
 * Output: ����B[0,1,...,n-1]
 *
 * Note:
 1.������ȡB[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]��ȱ�ٵ�A[i]��
 2.�������� B[i]= A[0]*A[1]*...*A[i-1]
 3.���ҵ����� B[i]  *=  A[i+1]*...*A[n-1] ע������治֮ͬ��

 * author: lcxanhui@163.com
 * time: 2019.6.25
 ******************************************************************************************************/
#include<iostream>
#include<vector>
using namespace std;

vector<int> multiply(const vector<int>& A)
{
	int len = A.size();
	vector<int> B(len);
	int ret = 1;
	for (int i = 0; i < len; ret *= A[i++])
		B[i] = ret;
	ret = 1;
	for (int i = len - 1; i >= 0; ret *= A[i--])
		B[i] *= ret;
	return B;
}

int main()
{
	vector<int> A = { 1,3,5,7,8 };
	vector<int> B;
	B = multiply(A);
	for (int i = 0; i < A.size(); i++)
		cout << B[i] << endl;
	return 0;
}