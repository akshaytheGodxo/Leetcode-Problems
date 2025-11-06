#include <bits/stdc++.h>
using namespace std;

int static matrix[1001][1001];

class Solution {
 	int solve(string a, string b, int n, int m) {
		if (n == 0 and m == 0) return 1;
		if (n == 0) return 0;
		if (m == 0) return 1;
		if (matrix[n-1][m-1] != -1) return matrix[n-1][m-1];

		if (a[n-1] == b[m-1]) {
			return matrix[n-1][m-1] = solve(a,b,n-1,m-1) + solve(a,b,n-1,m);
		} else {
			return matrix[n-1][m-1] = solve(a,b,n-1,m);
		}
	}
    int numDistinct(string s, string t) {
        memset(matrix, -1, sizeof(matrix));
        int ans = solve(s, t, s.size(), t.size());
        return ans;
    }
};

int main() {
	string s,t;
	cin >> s >> t;
	Solution st;
	cout << st.numDistinct(s, t);
	return 0;
}