/*****************************************************************************************************
 *         剑指offer第8题
 * 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 输入一个非减排序的数组的一个旋转，
   输出旋转数组的最小元素。 例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 NOTE：给出
   的所有元素都大于0，若数组大小为0，请返回0。
 *
 * Input: 旋转的数组vector<int> num
 * Output: 数组中的最小数
 *
 * Note:（二分查找）
 * 利用数组已经是排序的特性进行考虑，并不是太难，需要熟悉掌握各种排序和查找算法

 *****本程序需要考虑到特殊的情况，类似于本程序的最后的vector<int> num3中的情况，此时只能用顺序查找的方式
      但是在牛客网中不考虑此种情况也能通过所有的测试用例
 * authur: lcxanhui@163.com
 * time: 2019.4.19
 ******************************************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		int length = rotateArray.size();
		if (rotateArray.empty())
			return -1;
		int left = 0, right = length - 1;
		int mid = 0;                       //此时的初始值设为0，则计算mid时则为 left+...
		// rotateArray[left] >= rotateArray[right] 确保旋转
		while (rotateArray[left] >= rotateArray[right]) {
			// 分界点
			if (right - left == 1) {
				mid = right;
				break;
			}
			mid = left + (right - left) / 2;
			// rotateArray[left] rotateArray[right] rotateArray[mid]三者相等,见vector<int> num3
			// 无法确定中间元素是属于前面还是后面的递增子数组
			// 只能顺序查找
			if (rotateArray[left] == rotateArray[right] && rotateArray[left] == rotateArray[mid]) {
				return MinOrder(rotateArray, left, right);
			}
			// 中间元素位于前面的递增子数组，此时最小元素位于中间元素的后面
			if (rotateArray[mid] >= rotateArray[left]) {
				left = mid;
			}
			// 中间元素位于后面的递增子数组
			// 此时最小元素位于中间元素的前面
			else if(rotateArray[mid] <= rotateArray[right]){
				right = mid;
			}
		}
		return rotateArray[mid];
	}
private:
	// 顺序查找最小值
	int MinOrder(vector<int> &num, int left, int right) {
		int result = num[left];
		for (int i = left + 1; i < right; ++i) {
			if (num[i] < result) {
				result = num[i];
			}
		}
		return result;
	}
};

int main() {
	Solution s;
	//vector<int> num = {0,1,2,3,4,5};
	vector<int> num = {4,5,6,7,2,3};
	//vector<int> num = { 2,2,2,2,1,2 };
	//vector<int> num = {};
	int result = s.minNumberInRotateArray(num);
	cout << result << endl;
	return 0;
}