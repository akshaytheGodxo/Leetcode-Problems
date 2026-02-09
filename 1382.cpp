#include <bits/stdc++.h>
using namespace std;


  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution  {
	public:
	
	void addInorder(vector<int> &arr, TreeNode* root) {
		if (root == nullptr) {
			return ;
		}

		addInorder(arr, root->left);

		arr.push_back(root->val);

		addInorder(arr, root->right);
	}

    TreeNode* balanceBST(TreeNode* root) { 
		vector<int> ans;
		addInorder(ans, root);
		 TreeNode* tree =  createBalancedBST(ans, 0, ans.size()-1);
		 return tree;
    }

	TreeNode* createBalancedBST(vector<int> arr, int start, int end) {
		if (start > end) {
			return nullptr;

		}

		int mid = start + (end - start) / 2;

		TreeNode* leftTree = createBalancedBST(arr, start, mid-1);
		TreeNode* rightTree = createBalancedBST(arr, int mid + 1, int end);

		return new TreeNode(arr[mid], leftTree, rightTree);
	}
};
