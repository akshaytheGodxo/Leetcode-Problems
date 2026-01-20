#include <bits/stdc++.h>
using namespace std;

int matrix[201][201];
// knapsack problem approach
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto i : nums) sum += i;
        if (sum % 2 != 0) return false;

        sum /= 2;
        int n=nums.size();
        bool dp[n+1][sum+1];
        dp[0][0] = true;
        for (int i=1;i<n+1;i++) {
            dp[i][0] = true;
        }
        for (int i=1;i<sum+1;i++) {
            dp[0][i] = false;
        } 

        for (int i=1;i<=n;i++) {
            for (int j=1;j<=sum;j++) {
                dp[i][j] = dp[i-1][j];
                if (j >= nums[i-1]) {
                    dp[i][j] = (dp[i][j] || dp[i-1][j-nums[i-1]]);
                }
            }
        }

        return dp[n][sum];
    }
};

int main(int argc, char const *argv[])
{
    Solution st;
    vector<int> nums = {1,5,11,5};
    cout << st.canPartition(nums);
    return 0;
}
