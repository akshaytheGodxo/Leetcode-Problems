import java.util.*;




class Solution {
    class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode() {}
        TreeNode(int val) { this.val = val; }
        TreeNode(int val, TreeNode left, TreeNode right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }
      }

    public List<String> binaryTreePaths(TreeNode root) {
        List<String> ans = new ArrayList<>();
        StringBuilder comb = new StringBuilder();
        backtrack(root, ans, comb);
        return ans;
    }

    public void backtrack(TreeNode root, List<String> ans, StringBuilder comb) {
        if (root == null) {
            return ;
        }

        String val = Integer.toString(root.val);
        if (root.right == null && root.left == null) {
            comb.append(val);
            ans.add(comb.toString());
            return ;
        }
        String x1 = comb.toString() + val + "->";
        backtrack(root.right, ans, new StringBuilder(comb + val + "->"));
        backtrack(root.left, ans, new StringBuilder(comb + val + "->"));
    }
}