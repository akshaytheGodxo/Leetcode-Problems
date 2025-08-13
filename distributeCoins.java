public class distributeCoins {
    
}


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

class Solution {
    int moves = 0;

    public int distributeCoins(TreeNode root) {
        dfs(root);
        return moves;
    }

    private int dfs(TreeNode root) {
        if (root == null)
            return 0;
        int left_excess = dfs(root.left);
        int right_excess = dfs(root.right);
        
        moves += Math.abs(left_excess) + Math.abs(right_excess);
        return root.val + left_excess + right_excess - 1;
    }
}