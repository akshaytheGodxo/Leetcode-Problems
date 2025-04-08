#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void AddChildren(ListNode* &tail, int data) {
    ListNode* temp = new ListNode(data);
    ListNode* tail_ref = tail;

    if (tail == nullptr) {
        tail = temp;
    }

    while (tail_ref->next != nullptr) {
        tail_ref = tail_ref -> next;
    }
    tail_ref->next = temp;

}

void PrintList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        std::cout << temp->val << " ";
        temp = temp->next;
    }
    std::cout << '\n';
}

int calcSize(ListNode* head) {
    int size = 0;
    ListNode* temp = head;
    while (temp != nullptr) {
        size++;
        temp = temp->next;
    }
    return size;
}

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = head;
    int size = calcSize(dummy);
    n = size - n;
    int step = 0;
    while (dummy != nullptr) {
        if (step == n) {
            dummy = dummy->next->next;
            break;
        }
        else {
            
            dummy = dummy -> next;
            step++;
        }
    } 
    return dummy;
}
int main() {
    ListNode* node = new ListNode(1);
    AddChildren(node, 2);
    AddChildren(node, 3);

    ListNode* ans = removeNthFromEnd(node, 3);    
    PrintList(ans);
    return 0;
}
