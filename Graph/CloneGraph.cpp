#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
private: 
    unordered_map<Node*, Node*> m;
public:


    Node *cloneGraph(Node *node) {
        if (!node) return nullptr;
        Node* copy = new Node(node->val, {});
        m[node] = copy;
        queue<Node*>q;
        q.push(node);
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            for (Node* nbr : curr->neighbors) {
                if (m.find(nbr) == m.end()) {
                    m[nbr] = new Node(nbr->val, {});
                    q.push(nbr);
                }
                m[curr]->neighbors.push_back(m[nbr]);
            }            
        }

        return copy;
    }
};

int main() {
    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);

    a->neighbors = {b, c};
    b->neighbors = {a, d};
    c->neighbors = {a};
    d->neighbors = {b};
    Solution s;
    return 0;
}
