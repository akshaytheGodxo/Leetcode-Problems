// Longest Palinderomic Substring 

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), maxlength = 0;
        string ans;
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int diff = 0; diff < n; diff++) {
            for (int i = 0, j = i + diff; j < n; i++, j++) {
                cout << i << " " << j << " " << diff << "\n";
                if (i == j)
                    dp[i][j] = 1;
                else if (diff == 1)
                    dp[i][j] = (s[i] == s[j]) ? 2 : 0;
                else {
                    if (s[i] == s[j] && dp[i + 1][j - 1])
                        dp[i][j] = dp[i + 1][j - 1] + 2;
                }

                if (dp[i][j]) {
                    if (j - i + 1 > maxlength) {
                        maxlength = j - i + 1;
                        ans = s.substr(i, maxlength);
                    }
                }
            }
        }

        // for (int i=0;i<n;i++){
        //     for (int j=0;j<n;j++) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << '\n';
        // }
        return ans;
    }
};
int main() {
    // babad = bab, aba
    string s;
    cin >> s;
    Solution st;
    cout << st.longestPalindrome(s);

    return 0;
}

/*
    if we solve this problem using dp, using the matrix method i have come to realise that this works like a memory where we keep check of the past 
    substrings if they were palinderome or not and use that to keep check of the new one

    index of outer(diagonal back string) = i+1, j-1;
*/