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
    void construct(TreeNode *root, vector<string> &res, string nums)
    {
        if (root == nullptr)
        {
            return;
        }
        nums += to_string(root->val);
        if (root->left == nullptr && root->right == nullptr)
        {
            res.push_back(nums);
            return;
        }

        construct(root->left, res, nums);
        construct(root->right, res, nums);
        nums.pop_back();
    }

    int sumRootToLeaf(TreeNode *root)
    {
        vector<string> res;
        string nums = "";
        construct(root, res, nums);
        int ans = 0;
        for (auto i : res) cout << i << " ";
        for (int i = 0; i < res.size(); i ++)
        {
            int dec = stoi(res[i], nullptr, 2);
            ans += dec;
        }

        return ans;
    }
};

int main()
{
}