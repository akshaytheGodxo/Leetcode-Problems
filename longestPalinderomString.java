
import java.util.*;

public class longestPalinderomString {

    public static void main(String[] args) {
        Solution s = new Solution();
        Scanner sc = new Scanner(System.in);
        String st = sc.next();
        System.out.println(s.longestPalindrome(st));
    }
}

class Solution {

    public String longestPalindrome(String s) {
        int n = s.length(), maxLength = 0;
        String ans = "";
        boolean[][] dp = new boolean[n][n];

        for (int diff = 0; diff < n; diff++) {
            for (int i = 0, j = i + diff; j < n; i++, j++) {
                if (i == j) {
                    dp[i][j] = true; // Single character is always a palindrome
                 }else if (diff == 1) {
                    dp[i][j] = (s.charAt(i) == s.charAt(j)); // Two characters are palindrome if they are equal
                 }else {
                    dp[i][j] = (s.charAt(i) == s.charAt(j)) && dp[i + 1][j - 1]; // Check if inside part is palindrome
                }
                if (dp[i][j]) {
                    int length = j - i + 1;
                    if (length > maxLength) {
                        maxLength = length;
                        ans = s.substring(i, j + 1);
                    }
                }
            }
        }

        for (int i = 0;i < n;i++) {
            System.out.print("Row: " + i + " " );
            for (int j = 0;j < n;j++) {
                System.out.print( dp[i][j] + " ");
            }
            System.out.println();
        }

        return ans;
    }
}
