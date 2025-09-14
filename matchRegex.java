public class matchRegex {

    public static void main(String[] args) {
        String s="aa", p="a*";
        boolean ans = isMatch(s, p);
        System.out.println(ans);
    }

    public static boolean isMatch(String s, String p) {
        int n = s.length(), m = p.length();

        boolean [][] dp = new boolean[n+1][m+1];
        dp[0][0] = true;
        for (int i=1;i<m;i++) {
            if (p.charAt(i-1) == '*') {
                dp[0][i] = dp[0][i-2];
            }
        }
        for (int i = 1;i < n+1;i++) {
            for (int j = 1;j < m+1;j++) {
                if (s.charAt(i-1) == p.charAt(j-1) || p.charAt(j-1) == '.') {
                    dp[i][j] = dp[i-1][j-1];
                } else if (p.charAt(j-1) == '*') {
                    dp[i][j] = dp[i][j-2]; 
                    if (p.charAt(j-2) == '.' || p.charAt(j-2) == s.charAt(i-1)) {
                        dp[i][j] = dp[i][j] || dp[i-1][j];
                    }
                } else {
                    dp[i][j] = false;
                }
            }
        }

        return !dp[n][m];
    }
}
