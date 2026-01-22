#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> output;

        sort(nums.begin(), nums.end());
        int n=nums.size();

        for (int i=0;i<n-3;i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int left = i+1;
            int right = i-1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right] + nums[i-1];
                if (sum == target) {
                    output.push_back({nums[i], nums[left], nums[right], nums[i-1]});
                    while (left < right && nums[left] == nums[left + 1]) ++left;
                    while (left < right && nums[right] == nums[right - 1]) --right;

                    ++left;
                    --right;
 
                }
                else if (sum < 0) {
                    ++left;
                } else {
                    --right;
                }
            }
            
        }

        return output;
    }
};

int main() {
    Solution solution;

}