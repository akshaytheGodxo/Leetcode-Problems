#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int steps = INT_MAX;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            long long t = (long long)k * nums[i];
            auto it = upper_bound(nums.begin() + i, nums.end(), t);
            int m = n - (it - (nums.begin() + i));
            steps = min(steps, m);
        }
        return steps;
    }
};


int main() {
    vector<int> nums = {2,1,5};
    int k = 2;
    Solution s;
    cout << s.minRemoval(nums, k);
    return EXIT_SUCCESS
;}