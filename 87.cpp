#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<char>> dp(n+1, vector<char>(m+1));

        dp[0][0] = s1[0];

        
    }
};

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    
    Solution s;
    cout << s.isScramble(s1, s2);
    return 0;
}