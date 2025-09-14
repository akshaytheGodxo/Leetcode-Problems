import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
public class justPractiseSession {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
    }   
    
    
    public void levelOrderTraversal(TreeNode root) {
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        while (!q.isEmpty()) {
            int size = q.size();
            ArrayList<Integer> arr = new ArrayList<>(size);
            for (int i=0;i<size;i++) {
                TreeNode frontNode = q.poll();
                int idx = i;
                if (idx <= arr.size()) {
                    arr.add(i, frontNode.val);
                } else {
                    arr.add(frontNode.val);
                }

                if (frontNode.left != null) {
                    q.add(frontNode.left);
                } if (frontNode.right != null) {
                    q.add(frontNode.right);
                }
            }            
            System.out.println(arr);
        }
    }
}


class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    
    TreeNode() {}

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val   = val;
        this.left  = left;
        this.right = right;
    }
}