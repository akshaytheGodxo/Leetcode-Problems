#include <vector>
#include <iostream>
#include <algorithm>

// sort the initial array to make it ready for the binary search baby and then initialise two pointers simultaneously two check at each moment if it is equal to the search varibale fck yeas bitches

std::vector<int> twoSum(std::vector<int> nums, int target, int idx) {
    std::sort(nums.begin(), nums.end());
    int left = 0;
    int right = nums.size() - 1;
    std::vector<int> output;
    while (left < right) {
        int sum = nums[left] + nums[right];
        if (sum == target && left != right && (left != idx && right != idx)) {
            output.push_back(nums[left]);
            output.push_back(nums[right]);
            break;
        } else if (sum < target || left == idx) {
            left++;
        }else if (sum > target || right == idx){
            right--;
        }

    }
    return output;
}

std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    std::vector<std::vector<int>> output;
    std::sort(nums.begin(), nums.end());
    int n = nums.size();
    std::vector<int> window;
    int prevSum = 0;
    for (int i = 0;i < n;i++) {
        prevSum += nums[i];
        int search = 0 - prevSum;
        window.push_back(prevSum);

        std::vector<int> Tsum = twoSum(nums, search, i);
        if (Tsum.size() == 2) {
            window.push_back(Tsum[0]);
            window.push_back(Tsum[1]);
            // search if the window is already present in the fcking output or not
            std::sort(window.begin(), window.end());
            auto it = std::find(output.begin(), output.end(), window);
            if (!(it != output.end())) {
                output.push_back(window);
            }
        }
        prevSum = 0;
        window.clear();
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