/*****************************************************************************************************
 *         剑指offer第33题
 * 输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
   例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。
 *
 * Input:  一维数组
 * Output: 数组中所有数字组成的最小的数
 *
 * Note: （考虑到新建比较规则，并且涉及到大数问题，可能会有数据溢出，考虑字符串）
 * key:自定义一个比较大小的函数，比较两个字符串s1, s2大小的时候，先将它们拼接起来，比较s1+s2,和s2+s1那个大，
   如果s1+s2大，那说明s2应该放前面，所以按这个规则，s2就应该排在s1前面。
 * author: lcxanhui@163.com
 * time: 2019.5.15
 ******************************************************************************************************/
#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include <algorithm>
using namespace std;

//如果题目要求得出最大的数字，可以将比较器转换成从大到小排序即可
   //其中，数字转化为字符串的使用方法，参考别人的代码
static bool compare(const string &st1, const string &st2)
{
	string s1 = st1 + st2;
	string s2 = st2 + st1;
	return s1 < s2;      //降序排列，改为大于就是升序排列！！
}
string PrintMinNumber(vector<int> numbers)
{
	string res;
	if (numbers.size() <= 0)
		return res;
	vector<string> vec;
	for (int i = 0; i < numbers.size(); i++)
	{
		stringstream ss;        //使用输入输出流，头文件要包含#include<sstream>
		ss << numbers[i];      //读入数字给流处理
		string s = ss.str();   //转换成字符串
		vec.push_back(s);      //将字符串s压入vec中
	}
	//排序，传入比较器，从小到大排序
	// compare作为比较器供sort函数调用，因为不是单纯的比较两个数值的大小而是
	//比较两个数分别前后串起来数值的大小，所以要重写比较器
	sort(vec.begin(), vec.end(), compare);
	for (int i = 0; i < vec.size(); i++)
		res.append(vec[i]);        //拼接字符串，这就是最小的数字
	return res;
}

int main(void)
{
	vector<int> numbers{ 3,321,22,43 };
	string result = PrintMinNumber(numbers);
	cout << result;
	return 0;
}