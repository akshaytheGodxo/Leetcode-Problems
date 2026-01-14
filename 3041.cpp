#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> dp;
        int ans = 0;
        for (auto i : nums) {
            ans = max(ans, dp[i+1] = dp[i] + 1);
            ans = max(ans, dp[i] = dp[i-1] + 1);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution st;
    vector<int> nums = {8,10,6,12,9,12,2,3,13,19,11,18,10,16};
    st.maxSelectedElements(nums);    
    return 0;
}

