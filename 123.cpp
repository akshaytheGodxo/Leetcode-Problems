#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(n+1, 0);
        
        int cp = prices[0];
        for (int i=1;i<=n;i++) {
            if (prices[i-1] < cp) {
                cp = prices[i-1];
            } else {
                dp[i] = prices[i-1] - cp + dp[i-1];
            }
        }
        return dp[n];
    }
};


int main() {
    Solution s;
    vector<int> prices = {3,3,5,0,0,3,1,4};

    cout << s.maxProfit(prices);
    return 0;
}