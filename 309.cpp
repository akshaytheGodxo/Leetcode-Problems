#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int n=prices.size();
       vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
       for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            dp[i][j] = 0;
            if (j-1 > i-1) {
                dp[i] = max()
            }
        }
       }  
    }
};

int main() {
    Solution s;
    vector<int> prices = {1,2,3,0,2};
    cout << s.maxProfit(prices);
    return 0;
}