#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        map<int, int> indexes;
        int n = nums.size();
        for (int i = 0;i < n;i++) {
            indexes[nums[i]] = i;
        }
        sort(nums.begin(), nums.end());
        vector<int> maxNums;
        for (int i = n - k; i < n;i++ ) {
            maxNums.push_back(nums[i]);
        }
        vector<int> ans(maxNums.size(), 0);
        for (int i = 0;i < maxNums.size();i++) {
            int idx = indexes[maxNums[i]];
            ans[idx] = maxNums[i];
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {2,1,3,3};
    int k = 2;
    Solution s;
    vector<int> ans = s.maxSubsequence(nums, k);
    for (auto i : ans) cout << i << " ";
    return EXIT_SUCCESS;
}