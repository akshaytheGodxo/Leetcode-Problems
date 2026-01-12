#include <bits/stdc++.h>
using namespace std;

int matrix[1001][1001];

int solve(string s1, string s2, int n, int m) {
    
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++)
        {
            if (s1[i] == s2[j]) {
                dp[i+1][j+1] = dp[i][j] + s1[i];
            } else {
                dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
            }
        }
        
    }


    int total = 0;
    for (auto i : s1) total += i;
    for (auto i : s2) total += i;

    return total - 2*dp[n][m];

}

int minimumDeleteSum(string s1, string s2) {
    int ans = solve(s1, s2, s1.size(), s2.size());
    return ans;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    cout << minimumDeleteSum(s1, s2);
    return 0;
}