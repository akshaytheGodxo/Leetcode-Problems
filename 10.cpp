#include <bits/stdc++.h>
using namespace std;
bool isMatch(string s, string p) {
    vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size()+1));
    dp[s.size()][p.size()] = true;

    for (int i=s.size();i >= 0;i--) {
        for (int j=p.size()-1;j >= 0;j--) {
            bool find_match = (i < s.length() &&(s[i] == p[j] || p[j] == '.'));
            if (j+1 < p.length() && p[j+1] == '*') {
                dp[i][j] = dp[i][j+2] || (find_match && dp[i+1][j]);
            } else {
                dp[i][j] = find_match && dp[i+1][j+1];
            }
        }
    }
    for (auto i : dp) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << "\n";
    }
    return dp[0][0];
}

int main() {
    string s, p;
    cin >> s >> p;
    cout << isMatch(s,p);
    return 0;
}