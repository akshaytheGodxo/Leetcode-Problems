#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<int> res;
    int i = 0;

    bool dfs(TreeNode* root, vector<int>& v) {
        if (root == nullptr) return true;
        if (root->val != v[i++]) return false;

        if (root->left && root->left->val != v[i]) {
            res.push_back(root->val);
            return dfs(root->left, v) && dfs(root->right, v);
        }

        return dfs(root->left, v) && dfs(root->right, v);

    }

    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        return dfs(root, voyage) ? res : vector<int>{-1};   
    }
};



int main()
{
    TreeNode *node = new TreeNode(1);
    node->left = new TreeNode(2);
    

    Solution sol;
    vector<int> voyage = {2, 1};
    vector<int> ans = sol.flipMatchVoyage(node, voyage);
    for (auto i : ans) {
        cout << i << " ";
    }

    // sol.testThings();
    return 0;
}