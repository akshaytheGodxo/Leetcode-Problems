#include <bits/stdc++.h>
using namespace std;

struct BST {
    int data;
    BST* left;
    BST* right;
    BST(int val) {
        data = val;
        left = right = nullptr;
    }
};

BST* insert(BST* root, int value) {
    if (root == nullptr) {
        return new BST(value);
    }

    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

int heightOfBST(int arr[],int n, BST* root) {
    if (root == nullptr) return 0;

    return max(heightOfBST(arr, n, root->right),heightOfBST(arr,n,root->left)) + 1;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i=0;i<n;i++) {
        cin >> arr[i];
    }

    BST* root = nullptr;

    for(int i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }
    cout << heightOfBST(arr, n, root) << endl;
    return 0;
}