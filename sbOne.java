public class sbOne {
    public static void main(String[] args) {
        Solution s = new Solution();
        int [][] mat = {{1,0,1},{1,1,0},{1,1,0}};
        System.out.println(s.numSubmat(mat));
    }
}


class Solution {
    public int numSubmat(int[][] mat) {
        int row = mat.length, col = mat[0].length;

        int [][] dp = new int[row+1][col+1];
        int ans = 0;
        for (int i=0;i<row;i++) {
            for (int j=0;j<col;j++) {
                if (mat[i][j] == 1) {
                    dp[i+1][j+1] = Math.min(Math.min(dp[i+1][j], dp[i][j+1]), dp[i][j])+1;
                    ans += dp[i+1][j+1];
                }
            }
        }

        return ans;
    }
}