#include <bits/stdc++.h>
using namespace std;

int minPathSum(vector<vector<int>> &grid)
{
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m,0));

    dp[n-1][m-1] = grid[n-1][m-1];

    

}