#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int i = 0;
        int j = nums.size() - 1;
        int diff = -1;
        while (i < j) {
            if (nums[j] - nums[i] > diff) {
                diff = nums[j] - nums[i];
            } 
            if (nums[j] > nums[i]) {
                j--;
            } else {
                i++;
            }
        }

        return diff;
    }
};


int main() {
    vector<int> nums = {7,1,5,4};
    Solution s;
    int ans = s.maximumDifference(nums);
    cout << ans << "\n";
    return EXIT_SUCCESS;
}