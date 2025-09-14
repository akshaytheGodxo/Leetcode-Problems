package assignment;

import java.util.*;
public class q3 {

	static Scanner scn = new Scanner(System.in);

	public static void main(String[] args) {
		q3 m = new q3();
		BinaryTree bt = m.new BinaryTree();
		bt.levelOrderZZ();
	}

	private class BinaryTree {
		private class Node {
			int data;
			Node left;
			Node right;
		}

		private Node root;
		private int size;

		public BinaryTree() {
			this.root = this.takeInput(null, false);
		}

		public Node takeInput(Node parent, boolean ilc) {

			int cdata = scn.nextInt();
			Node child = new Node();
			child.data = cdata;
			this.size++;

			// left
			boolean hlc = scn.nextBoolean();

			if (hlc) {
				child.left = this.takeInput(child, true);
			}

			// right
			boolean hrc = scn.nextBoolean();

			if (hrc) {
				child.right = this.takeInput(child, false);
			}

			// return
			return child;
		}

		public void levelOrderZZ() {
			
			// write your code here
            Queue<Node> q = new LinkedList<>();
            q.add(root);
            List<Integer> result = new ArrayList<>();
            boolean leftToRight = true;
            while (!q.isEmpty()) {
                int size = q.size();
                List<Integer> ans = new ArrayList<>(size);
                for (int i = 0;i < size;i++) {
                    Node frontNode = q.element();
                    q.remove();
                    int index = leftToRight ? i : size - i - 1;
                    ans.add(index, frontNode.data);
                    if (frontNode.left != null) {
                        q.add(frontNode.left);
                    } 
                    if (frontNode.right != null) {
                        q.add(frontNode.right);
                    }
                }

                leftToRight = !leftToRight;
                result.addAll(ans);
                ans.clear();
            }

            for (int i = 0;i < result.size();i++) {
                System.out.print(result.get(i) + " ");
            }
            
		}

	}

}
