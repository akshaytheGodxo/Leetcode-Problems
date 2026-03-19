#include <bits/stdc++.h>
using namespace std;

class Solution{
public: 

    bool diffArray(vector<int> &nums, vector<vector<int>> &queries, int k) {
        int n=nums.size();
        vector<int> diff(n, 0);
        for (int i=0;i<k;i++) {
            int start = queries[i][0];
            int end = queries[i][1];
            int value = queries[i][2];
            diff[start] += value;

            if (end + 1 < n) diff[end+1] -= value;
        }


        for (int i=1;i<n;i++) {
            diff[i] += diff[i-1];
            
        }
        for (int i=0;i<n;i++) {
            if (diff[i] < nums[i]) return false;
        }

        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int st = 0, ed = queries.size()-1;
        int ans = -1;
        while (st < ed) {
            int mid = st + (ed - st)/2;
            if (diffArray(nums, queries, mid)) {
                ans = mid;
                ed = mid-1;
            } else {
                st = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<int>> queries = {
        {0,2,1},
        {0,2,1},
        {1,1,3}
    };
    vector<int> nums = {2,0,2};
    cout << s.minZeroArray(nums, queries);
    return 0;
}