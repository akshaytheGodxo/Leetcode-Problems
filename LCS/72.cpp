#include <bits/stdc++.h>
using namespace std;

int static matrix[501][501];


#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastIO ios_base::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

void solve() {
    
}

int32_t main() {
    fastIO
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}

class Solution {
public:
    int solve(string a, string b, int n, int m) {
        if (n == 0) return m;
        if (m == 0) return n;
        if (matrix[n][m] != -1) return matrix[n][m];
        
        if (a[n-1] == b[m-1]) {
            return matrix[n][m] =  solve(a, b, n-1, m-1);
        }

        else {
            // if (a[n-1] != b[m-1] && n > m) {
            //     return 1 + solve(a, b, n-1, m);
            // } else if (a[n-1] != b[m-1] && n < m) {
            //     return 1 + solve(a, b, n, m-1);
            // } else if (a[n-1] != b[m-1] && n == m) {
            //     return 1 + solve(a, b, n-1, m-1);
            // }

            int x1 = solve(a,b,n-1,m);
            int x2 = solve(a,b,n,m-1);
            int x3 = solve(a,b,n-1,m-1);


            return matrix[n][m] =  1 + min ({x1, x2, x3});
        }

    }

    int minDistance(string word1, string word2) {
        memset(matrix, -1, sizeof(matrix));
        int ans = solve(word1, word2, word1.size(), word2.size());
        return ans;
    }
};


int main() {
    Solution s; 
    string word1, word2;
    cin >> word1 >> word2;
    int ans = s.minDistance(word1, word2);
    cout << ans;
    return EXIT_SUCCESS;
}