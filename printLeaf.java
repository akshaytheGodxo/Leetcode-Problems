import java.util.*;

public class printLeaf {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Node root = TreeInput(sc);
        printLeafNodes(root);
    }

    private static Node TreeInput(Scanner sc) {
        int data = sc.nextInt();
        Node root = new Node(data);
        Queue<Node> queue = new LinkedList<>();
        queue.add(root);

        while (!queue.isEmpty()) {
            Node current = queue.poll();

            int leftData = sc.nextInt();
            if (leftData != -1) {
                current.left = new Node(leftData);
                queue.add(current.left);
            }

            int rightData = sc.nextInt();
            if (rightData != -1) {
                current.right = new Node(rightData);
                queue.add(current.right);
            }
        }

        return root;

    }

    private static void printLeafNodes(Node node) {
        if (node == null) return ;

        if (node.left == null && node.right == null) {
            System.out.print(node.data + " ");
            
        }

        printLeafNodes(node.left);
        printLeafNodes(node.right);
    }
}


class Node {
    int data;
    Node left;
    Node right;
    Node(int data) {
        this.data = data;
    }
}