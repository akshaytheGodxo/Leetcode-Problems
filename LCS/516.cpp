#include <bits/stdc++.h>
using namespace std;

int static t[1001][1001];

class Solution {
public:

    int solve(string &a, string &b, int n, int m) {
        if (n == 0 || m == 0) return 0;
        if (t[n][m] != -1) return t[n][m];

        if (a[n-1] == b[m-1]) {
            return t[n][m] = 1 + solve(a, b, n-1, m-1);
        } else {
            return t[n][m] = max(solve(a, b, n-1, m), solve(a, b, n, m-1));
        }
    }

    int longestPalindromeSubseq(string s) {
        memset(t, -1, sizeof(t));
        string k = s;
        reverse(s.begin(), s.end());
        int n = s.size();
        return solve(k, s, n, n);
    }
};

int main() {
    Solution s;
    string st;
    cin >> st;

    int ans = s.longestPalindromeSubseq(st);
    cout << ans;

    return EXIT_SUCCESS;
}