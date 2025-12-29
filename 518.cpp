#define ui unsigned int
#include <bits/stdc++.h>
using namespace std;

class Solution {
    private: 
    int solve(int amount, vector<int>& coins, int n, int &sum) {
        if (n == 0) return 0;

        if (sum + coins[n-1] == amount) {
            return 1 + solve(amount, coins, n-1, sum);
        } else if (sum + coins[n-1] < amount) {
            int k = sum + coins[n-1];
            return solve(amount, coins, n-1, k) + solve(amount, coins, n-1, sum);
        } else if (sum + coins[n-1] > amount){
            return 0;
        }
        
    }
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