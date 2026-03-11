#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
    }
};


int main() {
    Solution s;
    
    int n;
    cin >> n;
    vector<int> nums(n);
    for (auto &x : nums) cin >> x;

    for (auto i : s.largestDivisibleSubset(nums)) {
        cout << i << " ";
    }
    return 0;
}