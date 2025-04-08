#include <bits/stdc++.h>
using namespace std;


// class Solution {
// public:
// 	vector<int> pivotArray(vector<int>& nums, int pivot) {
// 		int n = nums.size();
// 		int ptr = 0;
// 		auto it = find(nums.begin(), nums.end(), pivot);
// 		int idx;
// 		if (it != nums.end()){
// 			idx = it - nums.begin();
// 		}

// 		while (ptr < n ) {
// 			if (nums[ptr] < pivot && ptr > idx) {
// 				swap(nums[ptr], nums[idx]);
// 				idx = ptr;
// 			} else if (nums[ptr] > pivot && ptr < idx) {
// 				swap(nums[ptr], nums[idx]);
// 				idx = ptr;
// 			} else if (nums[ptr] == pivot && ptr != idx) {
// 				swap(nums[ptr], nums[idx]);
// 				idx = ptr;
// 			}
// 			ptr++;
// 		}
// 		return nums;
// 	}
// };

class Solution {
public:
	vector<int> pivotArray(vector<int>& nums, int pivot) {
		int n = nums.size();
		vector<int> high;
		vector<int> low;
		int count = 0;
		for (int i = 0;i < n;i++) {
			if (nums[i] < pivot) {
				low.push_back(nums[i]);
			}
			if (nums[i] == pivot)
				count++;
		}
		while (count != 0) {
			low.push_back(pivot);
			count--;
		}
		for (int i = 0;i < n;i++) {
			if (nums[i] > pivot) 
		}

		return low;
	}
};

int main() {
	vector<int> nums = {9,12,5,10,14,3,10};
	int pivot = 10;
	Solution sol;
	vector<int> ans = sol.pivotArray(nums, pivot);
	for (auto i : ans)
		cout << i << " ";
	return 0;
}
