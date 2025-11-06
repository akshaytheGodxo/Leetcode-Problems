#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();

        vector<vector<int>> dp(m+1, vector<int>(n+1,0));
        int ans=0;
        for (int i=1;i<=m;i++) {
            for (int j=1;j<=n;j++) {
                if (matrix[i-1][j-1] == '1') {
                    dp[i][j] = dp[i][j-1] * dp[i-1][j];
                    ans = max(dp[i][j], ans);
                } 
                else {
                    if (matrix[i-1][j-2] == '1') {
                        dp[i][j] = dp[i][j-1] + 1;
                    }
                }
            }
        }

        for(auto &x : dp) {
            for (auto &y : x) {
                cout << y << " ";
            } cout << "\n";
        }
        cout << "Area: ";
        return ans;
    }
};



int main() {
    Solution solution;
    vector<vector<char>> matrix = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };

    cout << solution.maximalRectangle(matrix);
    return 0;
}