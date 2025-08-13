import java.util.*;

public class hahaLol {
    public static void main(String[] args) {
        Solution s = new Solution();
        int[][] queries = {{0, 1}, {2, 2}, {0, 3}};
        int n = 15;
        int [] ans = s.productQueries(n, queries);

        for (int i = 0;i < ans.length;i++) System.out.print(ans[i] + " ");
    }
}

class Solution {
    public int[] productQueries(int n, int[][] queries) {
        double mod = 1e9 + 7;
        List<Integer> powers;
        int []answers = new int[queries.length];
        powers = new ArrayList<>();
        int s = 0;
        int idx = 0;
        while (s < n) {
            double k = Math.pow(2, idx);
            powers.add((int)k);
            s += k;
            idx++;
        }
        for (int i = 0;i < queries.length;i++) {
            int prod = 1;
            for (int j = queries[i][0];j <= queries[i][1];j++) {
                prod = prod * powers.get(j) % (int)mod;
            }
            answers[i] = prod;
        }

        return answers;
    }
}