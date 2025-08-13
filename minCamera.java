public class minCamera {
    public static void main(String[] args) {
        TreeNode root = null;
        int [] values = {5, 3, 7, 2, 4, 6, 8};
        for (int val : values) {
            root = insert(root,val);
        }

        System.out.println("Inorder Traversal\n");
        printTree(root);

        Solution s = new Solution();
        int cameraPos = s.minCamera(root);
        System.out.println("\nCamera pos: "+ cameraPos);
    }
    
    public static TreeNode insert(TreeNode root, int val) {
        if (root == null) {
            return new TreeNode(val);
        }
        if (val < root.val) {
            root.left = insert(root.left,val);
        }
        else if (root.val < val) {
            root.right = insert(root.right,val);
        }
        return root;
    }

    public static void printTree(TreeNode root) {
        if (root != null) {
            printTree(root.left);
            System.out.print(root.val + " ");
            printTree(root.right);
        }
    }
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
    int Camera=0;
    public int minCameraCover(TreeNode root) {
        int c=minCamera(root);
        if (c==-1) {
            Camera++;
        }
        return Camera;
    }
    public int minCamera(TreeNode root) {
        if (root == null) return 0;
        int left=minCamera(root.left);
        int right=minCamera(root.right);
        if (left==-1 || right==-1) {
            Camera++;
            return 1;
        }

        else if (left==1 || right == 1) {
            return 0;
        }
        else {
            return -1;
        }
    }
}