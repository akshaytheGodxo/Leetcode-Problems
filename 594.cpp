#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int minNum = nums[0];
        int n = nums.size();
        int sz = 0;
        for (int i = 1;i < n;i++) {
            int currSize = 0;
            if (nums[i] == minNum + 1) {
                currSize = count(nums.begin(), nums.end(), nums[i]) + count(nums.begin(), nums.end(), minNum);
                // cout << minNum << "->" << currSize << " ";
                sz = max(sz, currSize);
            }
            minNum = nums[i];
        } 
        
        return sz;
    }
};

int main() {
    vector<int> nums = {1,3,2,2,5,2,3,7}; // 1 2 2 2 3 3 5 7
    Solution sol;
    cout << sol.findLHS(nums);  
    return 0;
}