/*****************************************************************************************************
 *         ��ָoffer��46��
 * ��1+2+3+...+n��Ҫ����ʹ�ó˳�����for��while��if��else��switch��case�ȹؼ��ּ������ж���䣨A?B:C����
 *
 * Input:   ����n
 * Output:  1+2+3+...+n�ĺ�
 *
 * Note: 
 * ���õ�·������֪ʶ
 ��ans=0ʱ����return false�����Ϊ0
 ��ans��0ʱ��ǰ�벿��Ϊ��ִ�����

 * author: lcxanhui@163.com
 * time: 2019.6.21
 ******************************************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

int Sum(int n) {
	int ans = n;
	//��·����
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