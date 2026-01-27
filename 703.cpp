#include <bits/stdc++.h>
using namespace std;


class KthLargest {
public:
    priority_queue<int> pq;
    int k;
    KthLargest(int k, vector<int>& nums) {
        for (auto i : nums) pq.push(i);
        this->k = k;
    }
    
    void printQ() {
        while (!pq.empty()) {
            cout << pq.top() << " ";
            pq.pop();
        }
    }

    int add(int val) {
        pq.push(val);
        int i = 0;
        vector<int> trash;
        while (i != k) {
            trash.push_back(pq.top());
            pq.pop();
            i++;
        }
        int ans = pq.top();
        for (auto i : trash) pq.push(i);

        return ans;
    }
};


int main() {
    int k;
    vector<int> nums = {4, 5, 8, 2};
    
    KthLargest* obj = new KthLargest(k, nums);
    obj->printQ();
}