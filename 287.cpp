#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
  		int n = nums.size();
  		int left = 1;
  		int right = n-1;
  		int i = 0;
  		int ans = 0;
  		while (left <= right) {
  			if (nums[i] == nums[left] || nums[i] == nums[right]) {
  				ans = i;
  				break;
  			}
  			left++;
  			right--;
  			i++;
  		}

  		return ans;
    }
};


int main() {
	vector<int> nums = {3,1,3,4,2};
	Solution s;
	cout << s.findDuplicate(nums);
	return 0;
}