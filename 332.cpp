#include <bits/stdc++.h>
using namespace std;
class Solution
{
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount+1, -1);
        dp[0] = 0;


        for (int coin:coins) {
            for (int w=coin;w<=amount;w++) {
                dp[w] = min(dp[w], dp[w-coin] + 1);
            }
        }

        return dp[amount];
    }
};
int main()
{
    Solution solution;
    return 0;
}