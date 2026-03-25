#include <bits/stdc++.h>
using namespace std;

class Solution {
public:


    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n=nums.size();
        int pref[n+1];
        pref[0] = 0;
        for (int i=1;i<=n;i++) {
            pref[i] = pref[i-1] + nums[i-1];
        }
        int count = 0;
        for (int i=0;i<=n;i++) {
            for (int j=0;j<i;j++) {
                if (pref[i] - pref[j] >= lower && pref[i] - pref[j] <= upper) count++;
            }
        }
        return count;
    }
};

int main(int argc, char const *argv[]) {
    vector<int> nums={-2,5,-1};
    int lower = -2;
    int upper = 2;
    Solution sol;
    cout << sol.countRangeSum(nums, lower, upper);
    return 0;
}
