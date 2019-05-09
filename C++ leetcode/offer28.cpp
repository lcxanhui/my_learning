/*****************************************************************************************************
 *         剑指offer第28题
 * 输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则打印出由字符a,b,c所能排列
   出来的所有字符串abc,acb,bac,bca,cab和cba。
 *
 * Input:  字符串
 * Output: 字符串的全排列
 *
 * Note: （分治法--思考）
 * 利用分治法递归的求取字符串的全排列，注意当字符串中有相同的字符时处理（需要判断交换字符时是否和后面的相同）
 * author: lcxanhui@163.com
 * time: 2019.5.9
 ******************************************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

void PermutationRecursive(string str, vector<string> &res, int start, int end);
bool HasSame(string &str, int start, int i);

vector<string> Permutation(string str)
{
	vector<string> res;
	if (str.size() == 0)
		return res;
	PermutationRecursive(str, res, 0, str.size());   // 递归调用
	return res;
}

void PermutationRecursive(string str, vector<string> &res, int start, int end)   //遍历第start位的所有可能性
{
	if (start == end)
		res.push_back(str);
	else
	{
		for (int i = start; i < end; i++)
		{
			if (!HasSame(str, start, i))
			{
				char tmp = str[i];       //交换第start位和第i位的字符
				str[i] = str[start];
				str[start] = tmp;
				PermutationRecursive(str, res, start + 1, end);
			}
		}
	}
}

bool HasSame(string &str, int start, int i) //从start位到第i位是否有重复的字符
{
	for (int j = start; j < i; j++)
	{
		if (str[j] == str[i])
			return true;
	}
	return false;
}

int main(void)
{
	// string str = "abc"; 
	string str="abb";
	vector<string> res;
	res=Permutation(str);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	return 0;
}