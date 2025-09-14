import java.util.*;
public class Main4 {

	static Scanner scn = new Scanner(System.in);

	public static void main(String[] args) {
		Main4 m = new Main4();
		BinaryTree bt1 = m.new BinaryTree();
		System.out.println(bt1.levelArrayList());
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

		public ArrayList<ArrayList<Integer>> levelArrayList() {

			// write your code here
			ArrayList<ArrayList<Integer>> result = new ArrayList<>();
			Queue<Node> q = new LinkedList<>();
			q.add(root);
			while (!q.isEmpty()) {
				int size = q.size();
				ArrayList<Integer> ans = new ArrayList<>(size);
				for (int i = 0;i < size;i++) {
					Node frontNode = q.element();
					q.remove();
					int idx = i;
					if (i <= ans.size()) {
						ans.add(i, frontNode.data);
					} else {
						ans.add(frontNode.data);
					}

					if (frontNode.left != null) {
						q.add(frontNode.left);
					} if (frontNode.right != null) {
						q.add(frontNode.right);
					}
				}
				result.add(ans);
				
			}
			return result;
		}

	}

}
