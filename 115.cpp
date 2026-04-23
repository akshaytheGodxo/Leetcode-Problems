#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	int solve(string a, string b, int n, int m) {
		if (n < 0) 
			return 0;
		if (m < 0) 
			return 0;

		if (a[n] == b[m]) {
			return  solve(a, b, n-1, m-1) + solve(a,b,n-1,m);
		} else {
			return  solve(a,b,n-1,m);
		}
	}

	int numDistinct(string s, string t) {
		int n=s.size(), m=t.size();
		return solve(s, t, n, m);
    }
};

int main() {
	Solution solution;
	
	return 0;
}