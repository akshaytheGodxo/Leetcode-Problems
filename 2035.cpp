#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    void solve(vector<int> nums,int &left, int &right, int i, int n, int ans) {
        if (i == n) {
            return ;
        }

        left += nums[i];
        ans = min(abs(left - right), ans);
        i++;
        solve(nums, left, right, i, n, ans);
        i--;
        left -= nums[i];
        right += nums[i];
        ans = min(abs(left - right), ans);
        i++;
        solve(nums, left, right, i, n, ans);
        i--;
        right -= nums[i];
    }

    int minimumDifference(vector<int> &nums) {
        int ans = INT_MAX;
        int i=0;
        int n=nums.size();
        int left = 0;
        int right = 0;
        solve(nums, left, right, i, n, ans);

        return ans;
    }

};

int main() {
    Solution s;
    vector<int> nums  = {2,-1,0,4,-2,-9};

    cout << s.minimumDifference(nums);
    return 0;
}