/*****************************************************************************************************
 *         剑指offer第44题
 * LL今天心情特别好,因为他去买了一副扑克牌,发现里面居然有2个大王,2个小王(一副牌原本是54张^_^)...他随机
 从中抽出了5张牌,想测测自己的手气,看看能不能抽到顺子,如果抽到的话,他决定去买体育彩票,嘿嘿！！“红心A,黑
 桃3,小王,大王,方片5”,“Oh My God!”不是顺子.....LL不高兴了,他想了想,决定大\小 王可以看成任何数字,并且
 A看作1,J为11,Q为12,K为13。上面的5张牌就可以变成“1,2,3,4,5”(大小王分别看作2和4),“So Lucky!”。LL决定
 去买体育彩票啦。现在,要求你使用这幅牌模拟上面的过程,然后告诉我们LL的运气如何，如果牌能组成顺子就输出
 true，否则就输出false。为了方便起见,你可以认为大小王是0。
 *
 * Input:  一维数组,长度为5（顺子）
 * Output: 是否为顺子
 *
 * Note: 
 * 1.先判断数组的长度，如果不为5则返回false;再对数组排序，统计大小王的个数（注意大小王的个数不能超过4个，需判断）
   2.再遍历去除大小王后的数组，如果存在相同数字则返回false;
   3.最后判断最后一个数字与去除大小王后的第一个数字之间的差值是否《=4

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