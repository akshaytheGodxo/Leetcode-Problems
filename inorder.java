import java.util.*;

public class inorder {

}

class TreeNode {

    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {}

    TreeNode(int val) {
        this.val = val;
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {

    public TreeNode buildTree(int[] preorder, int[] inorder) {
        return createTree(inorder,preorder, 0, inorder.length-1, 0, preorder.length-1);
    }
    public TreeNode createTree(int []in, int [] pre, int ilo, int ihi, int plo, int phi) {
           if (plo > phi || ilo > ihi) {
            return null;
           }
           TreeNode node = new TreeNode(pre[plo]);
           int idx = search(in, ilo, ihi, pre[plo]);
           int ne = idx - ilo;
           node.left = createTree(pre, plo+1, plo+ne, in, ilo, idx-1);
           node.right = createTree(pre, plo+ne+1, phi, in, idx+1, ihi);   
           return node;
    }

    public int search(int[] in, int si, int ei, int item) {
        for (int i = si;i <= ei;i++) {
            if (in[i] == item) {
                return i;
            }
        }
        return 0;
    }
}
