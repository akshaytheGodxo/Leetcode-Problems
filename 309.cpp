#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[5001][2][2];
    int recur(vector<int> prices, int i, int cooldown, bool buy) {
        if (i >= prices.size()) return 0;

        if (dp[i][cooldown][buy] != INT_MIN) return dp[i][cooldown][buy];

        if (buy) {
            int not_taken = INT_MIN, taken = INT_MIN;
            
            if (cooldown) {
                not_taken = recur(prices, i+1, false, true);
            } else {
                not_taken = recur(prices, i+1, false, true);
                taken = -prices[i] + recur(prices, i+1, false, false);
            }

            return dp[i][cooldown][buy] = max(taken, not_taken);
        } else {

            int sold = prices[i] + recur(prices, i+1, true, true);
            // else if skipp ? 
            int not_sold = recur(prices, i+1, false, false);
            return dp[i][cooldown][buy] = max(sold, not_sold);
        }

    }

    int maxProfit(vector<int>& prices) {
        for (int i=0;i<=prices.size();i++) 
            for (int j=0;j<2;j++) 
                for (int k=0;k<2;k++) 
                    dp[i][j][k] = INT_MIN;
        return recur(prices, 0, false, true);
    }
};

int main() {
    Solution s;
    vector<int> prices = {1,2,3,0,2};
    cout << s.maxProfit(prices);
    return 0;
}