#include <bits/stdc++.h>
using namespace std;

int static matrix[2501][2501];

int lengthOfLIS(vector<int> &nums)
{
    
}

int findNumberOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, 1);
    vector<int> ways(n,0);
    int max_n = dp[0];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[j] < nums[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
                if (dp[i] > max_n) {
                    ways[i] = 1;
                    max_n = dp[i];
                } else if (dp[i] == max_n){
                    ways[i] = ways[i-1]+1;
                } else {
                    ways[i] = ways[i-1];
                }
            }
        }
    }
    for (auto i : dp)
        cout << i << " ";
    cout << endl;
    for (auto i : ways) {
        cout << i << " ";
    }
    return ways[n-1];
}

int main()
{
    vector<int> nums = {1, 3, 5, 4, 7};

    int ans = findNumberOfLIS(nums);
    cout << ans;
    return 0;
}