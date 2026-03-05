#include <bits/stdc++.h>
class Solution {
public:
    int findMaxForm(std::vector<std::string>& strs, int m, int n) {
        int sz = strs.size();
        int dp[sz+1][m+1][n+1];
        memset(dp, 0, sizeof(dp));

        for (int i = 1;i<=sz;i++) {
            for (int j=0;j<=m;j++) {
                for (int k=0;k<=n;k++) {
                    dp[i][j][k] = dp[i-1][j][k];
                    int zeroes = std::count(strs[i-1].begin(), strs[i-1].end(), '0');
                    int ones = std::count(strs[i-1].begin(), strs[i-1].end(), '1');
                    if (zeroes <=j && ones <= k) {
                        dp[i][j][k] = std::max(dp[i-1][j][k], dp[i-1][j-zeroes][k-ones] + 1);
                    }
                }
            }
        }

        return dp[sz][m][n];
    }
};

int main() {
    std::vector<std::string> strs = {"10","0001","111001","1","0"};
    int n = 3, m = 5;
    Solution solution;
    std::cout << solution.findMaxForm(strs, m, n);
    return 0;
}