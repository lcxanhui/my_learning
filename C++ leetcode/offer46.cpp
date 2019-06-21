/*****************************************************************************************************
 *         剑指offer第46题
 * 求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
 *
 * Input:   数字n
 * Output:  1+2+3+...+n的和
 *
 * Note: 
 * 利用电路的与门知识
 当ans=0时，则return false，输出为0
 当ans》0时，前半部分为真执行求和

 * author: lcxanhui@163.com
 * time: 2019.6.21
 ******************************************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

int Sum(int n) {
	int ans = n;
	//电路与门
	ans && (ans += Sum(n - 1));
	return ans;
}

int main()
{
	int n;
	cin >> n;
	int ans=Sum(n);
	cout << ans;
	return 0;
}