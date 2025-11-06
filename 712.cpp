#include <bits/stdc++.h>
using namespace std;

int matrix[1001][1001];

int solve(string a, string b, int n, int m) {
    if (n == 0) return b[0]; 
    if (m == 0) return a[0];

    if (a[n-1] == b[m-1]) {
        return solve(a,b,n-1,m-1);
    } else {
        return min({solve(a,b,n-1,m) + a[n-1], solve(a,b,n,m-1) + b[m-1], solve(a,b,n-1,m-1) + min(a[n-1], b[m-1])});
    }

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