// Add Two Linked Lists

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int data) : val(data), next(nullptr) {}
    ListNode(int data, ListNode* next) : val(data), next(next) {}
};


void insert(ListNode* &head, int data) {

    // This is to create/ initialise a node if it doesn't have any value at the start
    ListNode* newNode = new ListNode(data);
    
    if (head == nullptr) {
        head = newNode;
        return;
    }
    // This is just normal tail insertion of a node
    ListNode* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    // added to the very last of the temp node
    temp->next = newNode;

}

void readVector(std::vector<int>& vec) {
    int value;
    std::string line;

    while (true) {
        std::getline(std::cin, line);
        if (line.empty()) {
            break;
        }
        std::istringstream stream(line);
        while (stream >> value) {
            vec.push_back(value);
        }
    }
}


void print(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

ListNode* reverse(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    ListNode* forward = nullptr;

    while (curr != nullptr) {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;

}
/*
    find the shorter linked list
    insert 0's infront of it to make it balanced
*/

int findLength(ListNode* head) {
    int length = 0;
    ListNode* temp = head;
    while (temp != nullptr) {
        length++;
        temp = temp->next;
    }
    return length;
}

void insertZeros(ListNode* &head, int amount) {

    for (int i = 0;i < amount;i++) {
        insert(head, 0);
    }
}




ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode();
    ListNode* res = dummy;
    int total = 0, carry = 0;

    while (l1 || l2 || carry) {
        total = carry;

        if (l1) {
            total += l1->val;
            l1 = l1->next;
        }
        if (l2) {
            total += l2->val;
            l2 = l2->next;
        }

        int num = total % 10;
        carry = total / 10;
        dummy->next = new ListNode(num);
        dummy = dummy->next;
    }

    return res->next;        
}


int main() {
    ListNode* head1 = nullptr;
    ListNode* head2 = nullptr;

    vector<int> arr1;
    vector<int> arr2;
    
    readVector(arr1);
    readVector(arr2);

    for (auto i : arr1) 
        insert(head1, i);   
    for (auto j : arr2) 
        insert(head2, j);
    
    // ListNode* sum = addTwo(head1, head2);
    // print(sum);
    ListNode* sum = addTwoNumbers(head1, head2);

    print(sum);
    return 0;
  

}