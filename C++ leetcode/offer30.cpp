/*****************************************************************************************************
 *         ��ָoffer��30��
 * ����n���������ҳ�������С��K��������������4,5,1,6,2,7,3,8��8�����֣�����С��4��������1,2,3,4,��
 *
 * Input:  һά����
 * Output: k������С��һά������
 *
 * Note: 
 * ���ֽ������
   1.ȫ����  O(nlogn)
   2.����partition�Ŀ�������  O(n)
   3.��������     O(nlogk)
   4.�������multiset����   O(nlogk)
   ������������ں������ݵ����Σ��Ҳ��ı�ԭ����
 * author: lcxanhui@163.com
 * time: 2019.5.13
 ******************************************************************************************************/
#include<iostream>
#include<vector>
#include <algorithm>
#include <functional>
using namespace std;

vector<int> MinKNum(vector<int> input, int k)
{
	int len = input.size();
	vector<int> res;
	if (len == 0 || k <= 0 || k > len)
		return res;
//���ձ������  sort(input.begin(),input.end()); ����֮��ȡǰk����
//for (int i = 0; i < k; i++)
//res.push_back(input[i]);
	for (int i = 0; i < k; i++)
		res.push_back(input[i]);
	//����ָ���ĵ����������Լ�һ����ѡ�ıȽϺ�����������һ��heap.O(N)
	make_heap(res.begin(), res.end());
	for (int i = k; i < len; i++)
	{
		if (input[i] < res[0])
		{
			//����heap��Ԫ��, �������������ĩβ.O(logN)
			pop_heap(res.begin(), res.end());
			res.pop_back();
			res.push_back(input[i]);
			//��ָ����������һ��Ԫ�ز��뵽heap��.O(logN)
			push_heap(res.begin(), res.end());
		}
	}
	//�������㷨��ͨ��ͨ����������pop_heap��ʵ��.N*O(logN)
	sort_heap(res.begin(), res.end());
	return res;
}

int main(void)
{
	vector<int> input{ 6, 1, 2, 5, 8, 4 };
	int k = 3;
	vector<int> res;
	res = MinKNum(input, k);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	return 0;
}