/*****************************************************************************************************
 *         ��ָoffer��8��
 * ��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת�� ����һ���Ǽ�����������һ����ת��
   �����ת�������СԪ�ء� ��������{3,4,5,1,2}Ϊ{1,2,3,4,5}��һ����ת�����������СֵΪ1�� NOTE������
   ������Ԫ�ض�����0���������СΪ0���뷵��0��
 *
 * Input: ��ת������vector<int> num
 * Output: �����е���С��
 *
 * Note:�����ֲ��ң�
 * ���������Ѿ�����������Խ��п��ǣ�������̫�ѣ���Ҫ��Ϥ���ո�������Ͳ����㷨

 *****��������Ҫ���ǵ����������������ڱ����������vector<int> num3�е��������ʱֻ����˳����ҵķ�ʽ
      ������ţ�����в����Ǵ������Ҳ��ͨ�����еĲ�������
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
		int mid = 0;                       //��ʱ�ĳ�ʼֵ��Ϊ0�������midʱ��Ϊ left+...
		// rotateArray[left] >= rotateArray[right] ȷ����ת
		while (rotateArray[left] >= rotateArray[right]) {
			// �ֽ��
			if (right - left == 1) {
				mid = right;
				break;
			}
			mid = left + (right - left) / 2;
			// rotateArray[left] rotateArray[right] rotateArray[mid]�������,��vector<int> num3
			// �޷�ȷ���м�Ԫ��������ǰ�滹�Ǻ���ĵ���������
			// ֻ��˳�����
			if (rotateArray[left] == rotateArray[right] && rotateArray[left] == rotateArray[mid]) {
				return MinOrder(rotateArray, left, right);
			}
			// �м�Ԫ��λ��ǰ��ĵ��������飬��ʱ��СԪ��λ���м�Ԫ�صĺ���
			if (rotateArray[mid] >= rotateArray[left]) {
				left = mid;
			}
			// �м�Ԫ��λ�ں���ĵ���������
			// ��ʱ��СԪ��λ���м�Ԫ�ص�ǰ��
			else if(rotateArray[mid] <= rotateArray[right]){
				right = mid;
			}
		}
		return rotateArray[mid];
	}
private:
	// ˳�������Сֵ
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