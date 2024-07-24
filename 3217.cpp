#include <iostream>
#include <vector>
#include <algorithm>
/**
 * Definition for singly-linked list. */


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void InsertData(ListNode* &head, int val) {
    ListNode* temp = new ListNode(val);
    ListNode* head_ref = head;
    if (head == nullptr) {
        head = temp;
        return ;
    }
    while (head_ref->next != nullptr) {
        head_ref = head_ref->next;
    }
    head_ref->next = temp;

}

void PrintList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        std::cout << temp->val << " ";
        temp = temp->next;
    }
    std::cout << "\n";
}

class Solution {
public:
    ListNode* modifiedList(std::vector<int>& nums, ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = nullptr; // Keep track of the previous node

        while (temp != nullptr) {
            int value = temp->val;
            std::vector<int>::iterator it = std::find(nums.begin(), nums.end(), value);

            if (it != nums.end()) {
                ListNode* toDelete = temp;
                if (prev == nullptr) { // Deleting the head node
                    head = temp->next;
                } else {
                    prev->next = temp->next;
                }
                temp = temp->next;
                delete toDelete;
            } else {
                prev = temp;
                temp = temp->next;
            }
        }
        return head;
    }
};

int main() {
    ListNode* node = new ListNode(1);
    InsertData(node, 2);
    InsertData(node, 3);
    InsertData(node, 4);
    std::vector<int> nums = {5};

    // std::cout << "Before deleting the node\n";
    // PrintList(node);
    // ListNode* temp = node;
    // node = node->next;
    // delete temp;
    // std::cout << "After deleting the node\n";
    // PrintList(node);
 
    Solution solution;
    ListNode* ans = solution.modifiedList(nums, node);
    PrintList(ans);

    return 0;
}