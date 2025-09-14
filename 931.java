import java.util.*;

class Solution {
    public int minFallingPathSum(int[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;
        int [][] dp = new int[m][n];
        dp[0] = matrix[0];
        for (int i = 1;i < m;i++) {
            for (int j = 0;j < n;j++) {
                if (j == 0) {
                    int val = Math.min(dp[i-1][0] + matrix[i][j], dp[i-1][1] + matrix[i][j]);
                    dp[i][j] = val;
                } else if (j == n-1) {
                    int val = Math.min(dp[i-1][n-1] + matrix[i][j], dp[i-1][n-2] + matrix[i][j]);
                    dp[i][j] = val;
                } else {
                    int val = Math.min(dp[i-1][j-1] + matrix[i][j], Math.min(dp[i-1][j] + matrix[i][j],matrix[i][j] + dp[i-1][j+1]));
                    dp[i][j] = val;
                }
            }
        }
        int mini = dp[m-1][0];
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                System.out.print(dp[i][j] + " ");
            }
            System.out.println();
        }
        for (int i = 0;i < n;i++) {
            mini = Math.min(mini, dp[m-1][i]);
        }

        return mini;
    }
}