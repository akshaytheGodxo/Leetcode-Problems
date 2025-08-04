#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> subarrayMajority(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans(queries.size(), -1);
        int idx = 0;
        for (auto arr : queries) {
            int l = arr[0];
            int r = arr[1];
            int thresh = arr[2];
            map<int, int> freq;
            int mini = INT_MAX;
            for (int i = l;i <= r;i++) {
                freq[nums[i]]++;
                if (freq[nums[i]] >= thresh) {
                    mini = min(nums[i], mini);
                }
            }
            ans[idx] = mini;
            idx++;
        }

        return ans;
    }
};

int main() {
    vector<int> nums = {1,1,2,2,1,1};
    vector<vector<int>> queries = {{0,5,4}, {0,3,3}, {2,3,2}};
    Solution s;
    vector<int> ans = s.subarrayMajority(nums, queries);
    for (auto i : ans) {cout << i << " ";}
    return 0;
}