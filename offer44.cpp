/*****************************************************************************************************
 *         ��ָoffer��44��
 * LL���������ر��,��Ϊ��ȥ����һ���˿���,���������Ȼ��2������,2��С��(һ����ԭ����54��^_^)...�����
 ���г����5����,�����Լ�������,�����ܲ��ܳ鵽˳��,����鵽�Ļ�,������ȥ��������Ʊ,�ٺ٣���������A,��
 ��3,С��,����,��Ƭ5��,��Oh My God!������˳��.....LL��������,��������,������\С �����Կ����κ�����,����
 A����1,JΪ11,QΪ12,KΪ13�������5���ƾͿ��Ա�ɡ�1,2,3,4,5��(��С���ֱ���2��4),��So Lucky!����LL����
 ȥ��������Ʊ��������,Ҫ����ʹ�������ģ������Ĺ���,Ȼ���������LL��������Σ�����������˳�Ӿ����
 true����������false��Ϊ�˷������,�������Ϊ��С����0��
 *
 * Input:  һά����,����Ϊ5��˳�ӣ�
 * Output: �Ƿ�Ϊ˳��
 *
 * Note: 
 * 1.���ж�����ĳ��ȣ������Ϊ5�򷵻�false;�ٶ���������ͳ�ƴ�С���ĸ�����ע���С���ĸ������ܳ���4�������жϣ�
   2.�ٱ���ȥ����С��������飬���������ͬ�����򷵻�false;
   3.����ж����һ��������ȥ����С����ĵ�һ������֮��Ĳ�ֵ�Ƿ�=4

 * author: lcxanhui@163.com
 * time: 2019.6.21
 ******************************************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


bool isContinuous(vector<int>& nums)
{
	int len = nums.size();
	if (nums.empty() || len != 5)
		return false;
	int joker = 0;
	sort(nums.begin(), nums.end());
	for(int i=0;i<len;i++)
	{
		if (nums[i] == 0)
			joker++;
    }
	if (joker > 4)
		return false;

	for (int i = joker + 1; i < len; i++)
	{
		if (nums[i] == nums[i-1])
			return false;
	}
	int dis = nums[4] - nums[joker];
	if (dis <= 4)
		return true;
	return false;
}

int main(void)
{
	vector<int> data{ 0,5,8,6,4 };
	//vector<int> data{ 0,5,4,6,4 };
	//vector<int> data{ 0,6,4 };
	bool ans = isContinuous(data);
	cout << ans;
	return 0;
}