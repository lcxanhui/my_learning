#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int partation(vector<int>& nums, int low, int high) 
{
	swap(nums[low], nums[(low + high) / 2]);
	int bound = nums[low];
	int left = low + 1, right = high;
	//  双指针，快速排序，交换不符合条件的数据
	while (left <= right) {
		while (left < high && nums[left] >= bound) left++;
		while (nums[right] < bound) right--;
		if (left < right)
			swap(nums[left++], nums[right--]);
		else break;
	}
	//  将bound放到换分完成后的两个数组之间，作为边界, 返回bound的位次
	swap(nums[low], nums[right]);
	return right;
}

int findKthLargest(vector<int>& nums, int k) {
	int low = 0, high = nums.size() - 1, mid = 0;
	while (low <= high) {
		mid = partation(nums, low, high);
		if (mid == k - 1) return nums[mid];
		else if (mid > k - 1) high = mid - 1;
		else low = mid + 1;
	}
	//  实际上返回 -1 代表没有第 k 大的数，这里不存在
	return -1;
}


int main()
{
	vector<int> nums{3,1,2,5,6,4,0,8,9};
	int k = 2;
	int res = findKthLargest(nums, k);
	cout << res << endl;
	return 0;
}