#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

int height(Node* root) {
    if (!root) return 0;
    return 1 + max(height(root->left), height(root->right));
}

void printLevel(Node* root, int level) {
    if (!root) return;

    if (level == 1)
        cout << root->data << " ";
    else {
        printLevel(root->left, level - 1);
        printLevel(root->right, level - 1);
    }
}


void reverseLevelOrderTraversal(Node* root) {
    int h = height(root);
    for (int i=h;i>=1;i--) {
        printLevel(root, i);
    }
    

}



Node* takeInput(int n) {
    unordered_map<int, Node*> mp;
    Node* root = nullptr;
    for (int i = 0; i < n; i++) {
        int parent, child;
        char lr;
        cin >> parent >> child >> lr;

        if (mp.find(parent) == mp.end())
            mp[parent] = createNode(parent);

        if (mp.find(child) == mp.end())
            mp[child] = createNode(child);

        if (root == nullptr)
            root = mp[parent];

        if (lr == 'L')
            mp[parent]->left = mp[child];
        else
            mp[parent]->right = mp[child];
    }

    return root;
}



int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        Node* root = takeInput(n);
        reverseLevelOrderTraversal(root);
    }

    return 0;
}