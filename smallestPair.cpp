#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return {-1, -1};

        map<int, int> freq;
        for (auto i : nums) {
            freq[i]++;
        }
        for (auto i : freq) {
            cout << i.first << " " << i.second << endl;
        }
        sort(nums.begin(), nums.end());
        for (int i=0;i<n-1;i++) {
            for (int j=i+1;j<n;j++) {
                if (freq[nums[i]] != freq[nums[j]]) {
                    return {nums[i], nums[j]};
                }
            }
        }


        return {-1, -1};
    }
};

int main() {
    Solution s;
    vector<int> nums ={3,5,4};
    for (auto i : s.minDistinctFreqPair(nums) ) cout << i << " ";
    return 0;
}