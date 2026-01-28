#include <bits/stdc++.h>
#include <vector>

using namespace std;


struct TreeNode {
    int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
public:
	void solve(vector<vector<int>> &ans, vector<int> local, int targetSum, TreeNode* root) {
		if (root == nullptr) {
			return ;
		}

		
		local.push_back(root.val);

		if (root->left == nullptr && root->right == nullptr) {
			if (targetSum == nullptr) {
				local.push_back(root->val);
				ans.push_back(local);
			}
		}

		solve(ans, local, targetSum - root->val, root->left); 
		solve(ans,local, targetSum - root->val, root->right);

		targetSum += root.val;
		

	}

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
  		      
    }
};

int main() {
	

	return 0;
}
