#define ui unsigned int
#include <bits/stdc++.h>
using namespace std;

class Solution {

    public:
    int change(int amount, vector<int>& coins) {  
        ui n=coins.size();
        
        vector<vector<ui>> dp(n+1, vector<ui>(amount+1, 0));
        for (ui i=1;i<=n;i++) {
            dp[i][0] = 1;
        }

        for (ui w = 1;w<=amount;w++) {
            for (ui i=1;i<=n;i++) {
                if (coins[i-1] <= w) {
                    dp[i][w] = dp[i][w - coins[i-1]] + dp[i-1][w];
                } else {
                    dp[i][w] = dp[i-1][w];
                }
            }
        }
        for (ui i = 0; i <= n; i++)
        {
            for (ui j = 0; j <= amount ; j++) 
            {
                cout << dp[i][j] << " ";
            } cout << "\n";
            
        }
        
        return dp[n][amount];
    }
};

int main() {
    Solution s;
    int amount = 5;
    vector<int> coins = {1, 2, 5};
    cout << s.change(amount, coins);
    return EXIT_SUCCESS;
}