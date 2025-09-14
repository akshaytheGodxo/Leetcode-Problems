package assignment;

import java.util.*;

public class q2 {

    static Scanner scn = new Scanner(System.in);

    public static void main(String[] args) {
        q2 m = new q2();
        int[] pre = takeInput();
        int[] in = takeInput();
        BinaryTree bt = m.new BinaryTree(pre, in);
        bt.display();
    }

    public static int[] takeInput() {
        int n = scn.nextInt();

        int[] rv = new int[n];
        for (int i = 0; i < rv.length; i++) {
            rv[i] = scn.nextInt();
        }

        return rv;
    }

    private class BinaryTree {

        private class Node {

            int data;
            Node left;
            Node right;
        }

        private Node root;
        private int size;

        public BinaryTree(int[] pre, int[] in) {
            this.root = this.construct(pre, 0, pre.length - 1, in, 0, in.length - 1);
        }

        private Node construct(int[] pre, int plo, int phi, int[] in, int ilo, int ihi) {
            if (plo > phi || ilo > ihi) {
                return null;
            }

            Node node = new Node();
            node.data = pre[plo];

            int idx = search(in, ilo, ihi, pre[plo]);
            int ne = idx - ilo;

            node.left = construct(pre, plo + 1, plo + ne, in, ilo, idx - 1);
            node.right = construct(pre, plo + ne + 1, phi, in, idx + 1, ihi);

            return node;
        }

        private int search(int[] in, int ilo, int ihi, int target) {
            for (int i = ilo; i <= ihi; i++) {
                if (in[i] == target) {
                    return i;
                }
            }
            return 0;
        }

        public void display() {
            this.display(this.root);
        }

        private void display(Node node) {
            if (node == null) {
                return;
            }

            String str = "";

            if (node.left != null) {
                str += node.left.data;
            } else {
                str += "END";
            }

            str += " => " + node.data + " <= ";

            if (node.right != null) {
                str += node.right.data;
            } else {
                str += "END";
            }

            System.out.println(str);

            this.display(node.left);
            this.display(node.right);
        }

    }

}
