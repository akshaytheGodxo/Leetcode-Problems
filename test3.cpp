#include <vector>
#include <iostream>
#include <algorithm>


std::vector<int> twoSum(std::vector<int> nums, int target) {
    std::sort(nums.begin(), nums.end());
    int left = 0;
    int right = nums.size() - 1;
    std::vector<int> output;
    while (left < right) {
        int sum = nums[left] + nums[right];
        if (sum == target) {
            output.push_back(nums[left]);
            output.push_back(nums[right]);
            break;
        } else if (sum < target) {
            left++;
        }else{
            right--;
        }

    }
    return output;
}

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5};
    std::vector<int> ans = twoSum(nums, 9);
    for (auto i : ans) {
        std::cout << i << "\n";
    }
    return 0;
}