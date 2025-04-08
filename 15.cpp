#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
// sort the initial array to make it ready for the binary search baby and then initialise two pointers simultaneously two check at each moment if it is equal to the search varibale fck yeas bitches



std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> output;
    int n = nums.size();

    for (int i = 0;i < n-2;i++) {
        if (i > 0 && nums[i] == nums[i-2]) continue;

        int left = i + 1;
        int right = n-1;

        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == 0) {
                output.push_back({nums[i], nums[left], nums[right]});
                //handling duplicates
                while (left < right && nums[left] == nums[left + 1]) ++left;
                while (left < right && nums[right] == nums[right - 1]) --right;
            
                ++left;
                --right;
            }
            else if (sum < 0) {
                ++left;
            }
            else {
                --right;
            }
        }
    }
    return output;
}

int main() {
    std::vector<int> nums = {-1,0,1,2,-1,-4,-2,-3,3,0,4};
    std::vector<std::vector<int>> output = threeSum(nums);

    for (auto i : output) {
        for (auto j : i) {
            std::cout << j << " ";
        }
        std::cout << "\n";
    }
    return 0;
}