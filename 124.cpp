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
    int MP = INT_MIN;
    int solve(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int l = max(solve(root->left), 0);
        int r = max(solve(root->right), 0);
        int new_pr = root->val + l + r;
        MP = max(MP, new_pr);

        return root->val+max(l,r);
    }

    int maxPathSum(TreeNode *root)
    {
        if (root == nullptr) return 0;
        if (root->right == nullptr && root->left == nullptr ) {
            return root->val;
        }
        
        solve(root);
        return MP;
    }
};
int main()
{
    Solution solution;
    return 0;
}