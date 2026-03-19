#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int t[1001][1001];
    int solve(string &a, string &b, int n, int m) {
        if (n == 0 || m == 0) return 0;
        if (t[n][m] != -1) return t[n][m];
        if (a[n-1] == b[m-1]) {
            return t[n][m] = 1 + solve(a,b,n-1, m-1);
        } else {
           return t[n][m] = solve(a,b,n-1,m) + solve(a,b,n,m-1);
        }
    }
    int countSubstrings(string s) {
        string k = s;
        reverse(k.begin(), k.end());
        return solve(k, s, k.size(), s.size());
    }
};

int main() {
    Solution s;
    string st;
    cin >> st;
    cout << s.countSubstrings(st);
    return 0;
}