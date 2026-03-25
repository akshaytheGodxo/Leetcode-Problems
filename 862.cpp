
#include <bits/stdc++.h>
using namespace std;

int shortestSubarray(vector<int>& nums, int k) {
    int n=nums.size();
    vector<int> pref(n, 0);
    pref[0] = nums[0];

    for (int i=1;i<n;i++) {
        pref[i] += pref[i-1] + nums[i];
    }
    
    deque<int> dq;
    int res = INT_MAX;
    for (int i=0;i<n;i++) {
        while (!dq.empty() && pref[i] - pref[dq.front() >= k]) {
            res = min(res, i - dq.front());
            dq.pop_front();
        }

        while (!dq.empty() && pref[i] <= pref[dq.back()]) {
            dq.pop_back();
        }

        dq.push_back(i);
    }
    return res;
}

int main() {
    // vector<int> nums1 = {1};
    // int k1 = 1;
    // cout << shortestSubarray(nums1, k1) << endl;  // Output: 1

    // vector<int> nums2 = {1, 2};
    // int k2 = 4;
    // cout << shortestSubarray(nums2, k2) << endl;  // Output: -1

    // vector<int> nums3 = {2, -1, 2};
    // int k3 = 3;
    // cout << shortestSubarray(nums3, k3) << endl;  // Output: 3

    vector<int> nums = {-28,81,-20,28,-29};
    int k = 89;

    cout << shortestSubarray(nums, k);


    return 0;
}
