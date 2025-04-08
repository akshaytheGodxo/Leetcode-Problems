#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int total = 0, res = nums[0];
		for (auto i  : nums) {
			if (total < 0) {
				total = 0;
			}

			total += i;
			res = max(total, res);
		}

		return res;

	}
};

int main(int argc, char const *argv[])
{
	vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
	Solution s;
	cout << s.maxSubArray(nums);
	return 0;
}