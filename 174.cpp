#include <bits/stdc++.h>

using namespace std;



class Solution {
public:
	int solve(vector<vector<int>>& matrix, int n, int m) {
		vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
		for (int i=n-1;i>=0;i--) {
			for (int j=m-1;j>=0;j--) {
				int num1= abs(0 - dp[i+1][j]);
				int num2 = abs(0 - dp[i][j+1]);
				bool is	
			}
		}		

		for (auto i : dp) {
			for (auto j : i) {
				cout << j << " ";
			}
			cout << endl;
		}
		return dp[n][m];
	}

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
    	// memset(matrix, 0, sizeof(matrix));
    	int n=dungeon.size();
    	int m=dungeon[0].size();
    	int ans = solve(dungeon, n, m);

    	return ans;
    }
};

int  main() {
	vector<vector<int>> n = {{-2,-3,3}, {-5, -10, 1}, {10, 30, -5}};
	Solution s;
	cout << s.calculateMinimumHP(n);
	return 0;
}