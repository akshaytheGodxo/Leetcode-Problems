#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dp[500001][2];
    int recur(vector<int>& stoneValue, int i, bool isAlice ) {
        if (i == stoneValue.size()) return 0;
        
        if (dp[i][isAlice] != -1) {
            return dp[i][isAlice];
        }

        int res = isAlice ? INT_MIN : INT_MAX;
        int total = 0;

        for (int k = 1;k<4;k++) {
            if (k + i > stoneValue.size()) break;
            total += stoneValue[k+i-1];

            if (isAlice) {
                res = max(res, total + recur(stoneValue, i+k, false));
            } else {
                res = min(res, recur(stoneValue, i+k, true));
            }

        }
        return dp[i][isAlice] = res;
    }   
    string stoneGameIII(vector<int>& stoneValue) {
        memset(dp, -1, sizeof(dp));
        int alice = recur(stoneValue, 0, true);
        int total = 0;
        for (auto i : stoneValue) total += i;
        int bob = total - alice;
        cout << alice;
        if (alice > bob) {
            return "Alice";
        } else if (alice < bob) {
            return "Bob";
        } else {
            return "Tie";
        }
    }
};