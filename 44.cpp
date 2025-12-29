#include <bits/stdc++.h>
using namespace std;

class Solution { 
    public:
       bool isMatch(string s, string p) {
            int n,m;
            n=s.size(), m=p.size();
            vector<vector<int>> dp(n+1, vector<int>(m+1, false));
            dp[0][0] = true;
            for (int i=0;i<m && p[i] == '*';i++) {
                dp[0][i+1] = true;
            }

            for (int i=1;i<=n;i++) {
                for (int j=1;j<=m;j++) {
                    if (p[j-1] == '*') {
                        dp[i][j] = dp[i-1][j] || dp[i][j-1];
                    } else {
                        dp[i][j] = (s[i-1] == p[j-1] || p[j-1] == '?') && dp[i-1][j-1];
                    }
                }
            }

            return dp[n][m];
        }
    };


int main() {
    Solution s;
    string str1, str2;
    cin >> str1 >> str2;
    cout << s.isMatch(str1, str2) << endl;
    return 0;
}