#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};



class Solution {
public:
    std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root) {
        
    }
};

void AddChildren(TreeNode* &root, int leftData, int rightData) {
    if (root != nullptr)
        {
            if (leftData != 0) // Assuming '\0' represents no child
                root->left = new TreeNode(leftData);
            if (rightData != 0) // Assuming '\0' represents no child
                root->right = new TreeNode(rightData);
        }

}

void PrintNode(TreeNode* root) {
    TreeNode* temp = root;
    TreeNode* temp2 = root;
    std::cout << "Right Node: ";
    while (temp->right != nullptr) {
        std::cout << temp->right->val << " ";
        temp = temp->right;
    }
    std::cout << "\nLeft Node: ";
    while (temp2->left != nullptr) {
        std::cout << temp2->left->val << " ";
        temp2 = temp2->left;
    }
    std::cout << "\n";
}

int main() {
    TreeNode* node = new TreeNode(3);
    AddChildren(node, 2, 3);
    AddChildren(node->left, 4, 5);
    AddChildren(node->right, 6, 7);
    PrintNode(node);
    return 0;
}
