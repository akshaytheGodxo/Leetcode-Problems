#include <bits/stdc++.h>

using namespace std;


int longestPalindromeSubseq(string s) {
    int n = s.size();
    if (n == 0) return 0;
    vector<vector<int>> dp(n, vector<int>(n));
    for (int diff = 0;diff < n;diff++) {
        
    }
}

int main() {
    string s;
    cin >> s;
    cout << longestPalindromeSubseq(s);
    return 0;
}