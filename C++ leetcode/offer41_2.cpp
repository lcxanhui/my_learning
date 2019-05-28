/*****************************************************************************************************
 *         ��ָoffer��41-2��
 * ��Ŀ����
 * С����ϲ����ѧ,��һ����������ѧ��ҵʱ,Ҫ������9~16�ĺ�,�����Ͼ�д������ȷ����100����������������
   �ڴ�,�����뾿���ж������������������еĺ�Ϊ100(���ٰ���������)��û���,���͵õ���һ������������Ϊ100
   ������:18,19,20,21,22�����ڰ����⽻����,���ܲ���Ҳ�ܿ���ҳ����к�ΪS��������������? 
 *
 * Input:  ��sum
 * Output: ��Ϊsum����������
 *
 * Note: ����������
 *  �����൱����һ�����ڣ����ڵ��������߾�������ָ�룬���Ǹ��ݴ�����ֵ֮����ȷ�����ڵ�λ�úͿ�ȡ�
 
 * author: lcxanhui@163.com
 * time: 2019.5.28
 ******************************************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > FindContinuousSequence(int sum)
{
	vector<vector<int> > resAll;
	if (sum <= 0)
		return resAll;
	//������㣬�൱�ڶ�̬���ڵ����ߣ������䴰���ڵ�ֵ�ĺ���ȷ�����ڵ�λ�úʹ�С
	int low = 1, high = 2;
	while (low < high)
	{
		//�����������ģ���Ϊ1��һ�����У���ô��͹�ʽ��(a0+an)*n/2
		int cur = (low + high)*(high - low + 1) >> 1;
		//��ȣ���ô�ͽ����ڷ�Χ����������ӽ������
		if (cur == sum)
		{
			vector<int> res;
			for (int i = low; i <= high; i++)
				res.push_back(i);
			resAll.push_back(res);
			low++;
		}
		//�����ǰ�����ڵ�ֵ֮��С��sum����ô�ұߴ�������һ��
		else if (cur < sum)
			high++;
		//�����ǰ�����ڵ�ֵ֮�ʹ���sum����ô��ߴ�������һ��
		else if (cur > sum)
			low++;
	}
	return resAll;
}

int main(void) {
	int sum = 15;
	vector<vector<int> > resAll = FindContinuousSequence(sum);
	for (int i = 0; i < resAll.size(); i++) {
		for (int j = 0; j < resAll[0].size(); j++)
		{
			cout << resAll[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}