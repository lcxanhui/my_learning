/*****************************************************************************************************
 *         ��ָoffer��14��
 * ����һ���������飬ʵ��һ�����������������������ֵ�˳��ʹ�����е�����λ�������ǰ�벿�֣����е�ż��
   λ������ĺ�벿�֣�����֤������������ż����ż��֮������λ�ò��䡣��
 *
 * Input:   һ������ĳ��Ⱥ��������
 * Output:  ���鰴����ż���������
 *
 * Note: ��˫ָ�뷨����������ȶ����Խ�����⣩
 * ��������б��������������������α��浽�µ����飬Ȼ�󽫱�����ż�����浽ͬһ���µ����飬
   ���õ������鸳ֵ��ԭ�������飻
 *
 * author: lcxanhui@163.com
 * time: 2019.4.21
 ******************************************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

void Reorder(vector<int> &array)
{
	int length = array.size();
	if (length == 0 || array.empty())
		return;
	vector<int> res;
	for (int i = 0; i < length; i++)     
	{
		if ((array[i] & 0x1) == 1)        //�������е�������������£����浽�µ�res
			res.push_back(array[i]);
	}
	for (int i = 0; i < length; i++)
	{
		if ((array[i] & 0x1) == 0)        //�������е�����ż������£����浽�µ�res
			res.push_back(array[i]);
	}
	array = res;
}

int main(void)
{
	int n, tmp;
	vector<int> arr;
	cin >> n;
	int i = n;
	while (n--)
	{
		cin >> tmp;
		arr.push_back(tmp);
	}

	Reorder(arr);
	for (int j = 0; j < i; j++)
		cout << arr[j] << " ";
	cout << endl;
	return 0;

}