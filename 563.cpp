#include <bits/stdc++.h>
using namespace std;

#define nl nullptr

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
    int sum = 0;
    int leftSum =0;
    int rightSum = 0;
    void solve(TreeNode* root) {
        if (root == nl) return ;

        leftSum = root->left->val;
        rightSum = root->right->val;

        sum += abs(leftSum - rightSum);

        

        solve(root->right);
        solve(root->left);

    }

    int findTilt(TreeNode* root) {
        solve(root);

        return sum;
    }
};

