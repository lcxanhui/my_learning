/*****************************************************************************************************
 *              剑指offer第52题
 * 给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]
   *...*A[n-1]。不能使用除法。
 *
 * Input:  数组A[0,1,...,n-1]
 * Output: 数组B[0,1,...,n-1]
 *
 * Note:
 1.本题求取B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]，缺少第A[i]项
 2.从左到右算 B[i]= A[0]*A[1]*...*A[i-1]
 3.从右到左算 B[i]  *=  A[i+1]*...*A[n-1] 注意和上面不同之处

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