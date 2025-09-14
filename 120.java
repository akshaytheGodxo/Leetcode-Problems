import java.util.*;
class triangle {
    public static void main(String[] args) {
        Solution s = new Solution();
        List<List<Integer>> triangle = new ArrayList<>();
    }
}
class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        List<List<Integer>> dp = new ArrayList<>();
        for (int i = 0;i < triangle.size();i++)
            dp.add(new ArrayList<>());
        dp.get(0).add(triangle.get(0).get(0));
        int n = triangle.size();
        for (int i = 1;i < n;i++) {
            for (int j = 0;j < triangle.get(i).size();j++) {
                int m = triangle.get(i-1).size();
                if (j == 0 ) {
                    int val = triangle.get(i).get(j) + dp.get(i-1).get(0);
                    dp.get(i).add(j, val); 
                } else if (j == triangle.get(i).size() - 1) {
                    int val = triangle.get(i).get(j) + dp.get(i-1).get(m-1);
                    dp.get(i).add(j, val);
                } else {
                    Integer val = Math.min(dp.get(i-1).get(j-1) + triangle.get(i).get(j), dp.get(i-1).get(j) + triangle.get(i).get(j));
                    dp.get(i).add(j, val);
                }
            }
        }
        for (int i=0;i<dp.size();i++) {
            for (int j=0;j<dp.get(i).size();j++) {
                System.out.print(dp.get(i).get(j) + " ");
            }
            System.out.println();
        }
        int s = dp.size();
        int ans = Collections.min(dp.get(s-1));

        return ans;
    }
}