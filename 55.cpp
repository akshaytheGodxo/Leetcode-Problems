#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return true;
        vector<int> dp(n);

        dp[0] = nums[0];
        for (int i = 1; i < n; i++) {
            // dp[i] ko pichli dp ki value se badaho end me check karo ki
            // dp[n-1] > size of array or not
            if (nums[dp[i]] == 0 && dp[i] < n - 1)
                return false;
            int jump = max(nums[i], dp[i - 1]);

            dp[i] = jump;
        }
        std::cout << dp[n-1] << "\n";
        if (dp[n - 1] >= n)
            return true;
        else
            return false;
    }
};
int main() {
	std::vector<int> nums = {2,3,1,1,4};
	Solution sol;

	cout << sol.canJump(nums);
	return 0;
}