#include <bits/stdc++.h>
using namespace std;
int static t[1001][1001];

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
int minInsertions(string s)
{
    int sz = s.size();
    int ls = longestPalindromeSubseq(s);    
    return sz - ls;
}

int main()
{
    string s;
    cin >> s;
    cout << minInsertions(s);
    return 0;
}