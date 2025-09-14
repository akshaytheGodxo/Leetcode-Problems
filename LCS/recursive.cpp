#include <bits/stdc++.h>

using namespace std;


int static t[1001][1001];

// pure recursive
int longestCommonSub(string a,string b,int n,int m) {
    if (n == 0 || m == 0) return 0;


    // choice diagram
    if (a[n-1] == b[m-1]) {
        return 1 + longestCommonSub(a,b,n-1,m-1);
    } else {
        return max(longestCommonSub(a,b,n-1,m) , longestCommonSub(a,b,n,m-1));
    }

}

// recursive + memoization
int longestCommonSubs(string &a, string &b, int n, int m) {
    if (t[n][m] != -1) return t[n][m];


    if (n == 0 || m == 0) return 0;

    if (a[n-1] == b[m-1]) {
        return t[n][m] = 1 + longestCommonSubs(a, b, n-1, m-1);
    } else {
       return t[n][m] = max(longestCommonSubs(a, b, n-1, m), longestCommonSubs(a, b, n, m-1));
    }
}

int main() {
    string a;
    string b;
    cin >> a >> b;
    memset(t, -1, sizeof(t));
    int ans = longestCommonSubs(a, b, a.size(), b.size());
    cout << ans;
    return 0;
}