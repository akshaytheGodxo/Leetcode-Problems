#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 

class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        ListNode* temp = head;

        stack<ListNode*> st;

        while(temp != nullptr) {
            while (!st.empty() && temp->val > st.top()->val) {
                st.pop();
            }

            st.push(temp);
            temp = temp->next;
        }

        ListNode* ans = NULL;
        while (!st.empty()) {
            temp = st.top();
            st.pop();
            temp->next = ans;
            ans = temp;
        }

        return temp;
    }
};

void insertNode(int value, ListNode* &head) {
    ListNode* temp = head;
    while (temp -> next != nullptr) {
        temp = temp->next;
    }

    ListNode* newNode = new ListNode(value);

    temp->next = newNode;
}

void printNode(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << "Node: " << temp->val << "\n";
        temp = temp->next;
    }   
}

int main() {
    ListNode* head = new ListNode(5);
    insertNode(2, head);
    insertNode(13, head);
    insertNode(3, head);
    insertNode(8, head);
    printNode(head);
    return EXIT_SUCCESS;
}