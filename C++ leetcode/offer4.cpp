/*****************************************************************************************************
 *         剑指offer第4题
 *请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换
  之后的字符串为We%20Are%20Happy

 * Input:  字符串str
 * Output: 替换后的字符串
 *
 * Note: （注意内存分配的情况）
 * 先对字符串进行遍历，求取字符串的长度以及空格的数量，再构建新的字符串的长度，并从原字符串最后
 * 进行遍历，进行替换
 ******************************************************************************************************/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void replaceSpace(char *str, int length) {
	if (str == NULL && length < 0)
		return;
	int oldlen = strlen(str);          // strlen函数求取字符串的长度
	int blank = 0;
	for (int i = 0; i < oldlen; i++)
	{
		if (str[i] == ' ')
			blank++;
	}
	int newlen = oldlen + blank * 2;
	while (newlen > oldlen && newlen > 0) {    // 循环条件
		for (int j = oldlen; j >= 0; j--)    // 从原字符串的最后开始遍历
		{
			if (str[j] == ' ')
			{
				str[newlen--] = '0';
				str[newlen--] = '2';
				str[newlen--] = '%';
			}
			else
				str[newlen--] = str[j];
		}
	}
}

int main()
{
	char str[20]="a d ef c";

	replaceSpace(str, 20);
	cout << str << endl;

	system("pause");
	return 0;
}