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
class Solution {
public:
    int findDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return max(findDepth(root->left), findDepth(root->right)) + 1;
    }

    void trackDepth(TreeNode* root, int curr, int depth,
                    vector<TreeNode*>& res) {
        if (root == nullptr) {
            return;
        }
        if (curr == depth - 1) {
            res.push_back(root);
            return;
        }
        trackDepth(root->left, curr + 1, depth, res);
        trackDepth(root->right, curr + 1, depth, res);
    }
    TreeNode* lca(TreeNode* root, TreeNode* a, TreeNode* b) {
        if (!root || root == a || root == b)
            return root;
        TreeNode* left = lca(root->left, a, b);
        TreeNode* right = lca(root->right, a, b);
        if (left && right)
            return root;
        return left ? left : right;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int depth = findDepth(root);
        int curr = 0;
        vector<TreeNode*> res;
        trackDepth(root, curr, depth, res);

        TreeNode* ans = res[0];
        for (int i = 1; i < res.size(); i++) {
            ans = lca(root, ans, res[i]);
        }
        return ans;
    }
};