#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int mod = 1e9 + 7;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> pow2(n, 1);
        int res = 0, left = 0, right = n - 1;
        for (int i = 1;i < n;i++) {
            pow2[i] = (pow2[i - 1] * 2) % mod;
        }
        while (left <= right) {
            if (nums[left] + nums[right] <= target) {
                res = (res + (pow2[right - left])) % mod;
                ++left;
            } else {
                --right;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2,3,3,4,6,7};
    int target = 12;
    cout << sol.numSubseq(nums, target);
    return 0;
}