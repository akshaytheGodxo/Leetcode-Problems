#include <bits/stdc++.h>
using namespace std;
// dp[i] = max(dp[i], prev_profit + prices[i] - cp)

static int memo[100001][5];
class Solution {
public:
    int solve(vector<int>& prices, int i, int tl) {
        if (i == prices.size()) {
            return 0;
        } 

        if (tl == 0) {
            return 0;
        }

        if (memo[i][tl] != -1) {
            return memo[i][tl];
        }

        int ans1 = solve(prices, i+1, tl);

        bool buy = (tl % 2== 0);
        int ans2 = 0;
        if (buy) {
            ans2 = -prices[i] + solve(prices, i+1, tl-1);
        } else {
            ans2 = prices[i] + solve(prices, i+1, tl-1);
        }
        return memo[i][tl] = max(ans1, ans2);
    }

    int maxProfit(vector<int>& prices) {
        
        memset(memo, -1, sizeof(memo));
        return solve(prices, 0, 4);
    }
};


int main() {
    Solution s;
    vector<int> prices = {1,2,4,2,5,7,2,4,9,0};

    cout << s.maxProfit(prices);
    return 0;
}