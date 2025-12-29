#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, 0));
        
    }
};

int main() {
    Solution s;
    int amount = 5;
    vector<int> coins = {1, 2, 5};
    cout << s.coinChange(coins, amount);
    return EXIT_SUCCESS;
}