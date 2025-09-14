import java.util.*;
class MaximalSquare {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int m = sc.nextInt();
        int n = sc.nextInt();
        char[][] matrix = new char[m][n];

        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                matrix[i][j] = sc.next().charAt(0);
            }
        }

        Solution s = new Solution();
        System.out.println(s.maximalSquare(matrix));

    }
}


class Solution {
    public int maximalSquare(char[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;
        int[][] dp = new int[m+1][n+1];
        int ans = 0;
        for (int i=1;i<=m;i++) {
            for (int j=1;j<=n;j++) {
                if (matrix[i-1][j-1] == '1') {
                    dp[i][j] = Math.min(dp[i-1][j-1], Math.min(dp[i-1][j], dp[i][j-1])) + 1;
                    
                    ans = Math.max(ans, dp[i][j]);
                }
            }
        }

        return ans * ans;
    }
}