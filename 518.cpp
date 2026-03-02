#define ui unsigned int
#include <bits/stdc++.h>
using namespace std;

class Solution {

    public:
    int change(int amount, vector<int>& coins) {  
        int n=coins.size();
        int dp[n+1][amount+1];
        
        for (int i=1;i<=n;i++) {
            dp[i][0] = 1;
        } 
        for (int i=1;i<=amount;i++) {
            dp[0][i] = 0;
        }


        for (int i=1;i<=n;i++) {
            for (int j=1;j<=amount;j++) {
                dp[i][j] = dp[i-1][j];
                if (j >= coins[i-1]) {
                    dp[i][j] = max(dp[i-1][j], dp[i][j - coins[i-1]] + dp[i-1][j]);
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