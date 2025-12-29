#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    vector<long long> countStableSubarrays(vector<int>& nums, vector<vector<int>>& queries) {
        vector<ll> ans;
        
        for (auto q:queries) {
            ll cnt=1, sz=1;
            int prev = nums[q[0]];
            for (int i=q[0]+1;i<=q[1];i++) {
                // cout << prev <<  nums[i] << " ";
                if (nums[i] >= prev) {
                    sz++;
                    cnt += sz;
                } else {
                    sz = 1;
                    cnt += 1;
                }
                prev = nums[i];
            }
            // cout << endl;

            ans.push_back(cnt);
        }

        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {3,1,2};
    vector<vector<int>> queries = {{0,1 }, {1, 2}, {0, 2}};
    vector<ll> ans = s.countStableSubarrays(nums, queries);

    for (auto i : ans) {
        cout << i << " ";
    }
    return 0;
}