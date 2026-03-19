#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        for (int i=0;i<nums.size();i++) {
            for (int j=0;j<nums.size();j++) {
                if (nums[i] % nums[j] == 0 || nums[j] % nums[i] == 0) {
                    st.insert(nums[j]);
                } else {
                    st.erase(nums[j]);
                }
            }
        }

        vector<int> ans;
        for (auto i : st) {
            ans.push_back(i);
        }
        reverse(ans.begin(), ans.end());
        return ans;
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