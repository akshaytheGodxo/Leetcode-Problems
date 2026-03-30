#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[1001][2][101];
    int recur(bool buy, int i, int k, vector<int> prices) {
        if (i >= prices.size()) return 0;

        if (dp[i][buy][k] != -1) return dp[i][buy][k];

        if (buy) {
            int purchased = k > 0 ? -prices[i] + recur(false, i+1, k-1, prices) : INT_MIN;
            int not_purchased = recur(true, i+1, k, prices);

            return dp[i][buy][k] = max(purchased, not_purchased);
        }

        else {
            int sell = prices[i] + recur(true, i+1, k, prices);
            int not_sell = recur(false, i+1, k, prices);
            return dp[i][buy][k] = max(sell, not_sell);
        }
    }

    int maxProfit(int k, vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        int ans=recur(true, 0, k, prices);
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> prices = {3,2,6,5,0,3};
    int k=2;
    cout << solution.maxProfit(k, prices);
    return 0;
}