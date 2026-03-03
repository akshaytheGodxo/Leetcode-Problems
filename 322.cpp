#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<int> dp(amount + 1, n);

        // for (int i=1;i<=amount;i++) {
        //     dp[i] = dp[i-1];
        //     if (i >= coins[i-1]) {
        //         dp[i] = max(dp[i-1], dp[i-coins[i-1]] + coins[i-1]);
        //     }
        // }

        for (int coin : coins)
        {
            for (int w = coin; w <= amount; w++)
            {
                dp[w] = min(dp[w], dp[w - coin] + 1);
            }
        }
        return dp[amount] == n ? -1 : dp[amount];
    }
};

int main()
{
    Solution s;
    int amount = 5;
    vector<int> coins = {1, 2, 5};
    cout << s.coinChange(coins, 11);
    return 0;
}
