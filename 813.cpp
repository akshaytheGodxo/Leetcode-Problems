#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        vector<int> c = nums;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int cs = 0;
        int idx = n-1;
        int t = k;
        while (t-1 != 0) {
            cs += nums[idx];
            t--;
        }
        int total = 0;
        for (int i = 0;i<n-k+1;i++) {
            total += nums[i];
        }
       
        
        double avg = total / (n-k + 1);
        avg += cs;
        return avg;
    }
};


int main() {
    Solution s;

    vector<int> nums = {9,1,2,3,9};
    int k = 3;
    cout << s.largestSumOfAverages(nums, k);
    return 0;
}