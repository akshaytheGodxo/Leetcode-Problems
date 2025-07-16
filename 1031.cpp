#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(vector<int> nums, int firstLen, int secondLen) {
        int n = nums.size();
        vector<int> dp1(n,0), dp2(n,0);
        int s1 = 0;
        for (int i = 0;i < n;i++) {
            if (i < firstLen) {
                s1 += nums[i];
                dp1[i] = s1;
            } else {
                s1 += nums[i] - nums[i - firstLen];
                dp1[i] = max(s1, dp1[i-  1]);
            }
        }
        int s2 = 0;
        for (int i = n - 1;i >= 0;i--) {
            if (i + secondLen >n - 1) {
                s2 += nums[i];
                dp2[i] = s2;
            } else {
                s2 += nums[i] - nums[i+secondLen];
                dp2[i] = max(s2, dp2[i+1]);
            }
        }

        int ans = 0;
        for (int i = firstLen - 1;i < n - secondLen;i++) {
            ans = max(dp1[i] + dp2[i+1], ans);
        }
        return ans;
    }

    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        return max(helper(nums, firstLen, secondLen), helper(nums, secondLen,  firstLen));
    }
};

int main() {
    Solution s;
    vector<int> nums = {2,1,5,6,0,9,5,0,3,8};
    int firstlen = 4;
    int secondlen = 3;
    cout << s.maxSumTwoNoOverlap(nums, firstlen, secondlen);
    return 0;
}