#include <iostream>
#include <deque>
#include <vector>

std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
    std::deque<int> deq; // Deque to store indices
    std::vector<int> result; // Vector to store the results

    for (int i = 0; i < nums.size(); ++i) {
        // Remove elements out of the current window
        if (!deq.empty() && deq.front() == i - k) {
            deq.pop_front();
        }

        // Remove elements that are not useful
        while (!deq.empty() && nums[deq.back()] <= nums[i]) {
            deq.pop_back();
        }

        // Add the current element at the back of the deque
        deq.push_back(i);

        // Store the maximum element of the current window
        if (i >= k - 1) {
            result.push_back(nums[deq.front()]);
        }
    }

    return result;
}

int main() {
    std::vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    std::vector<int> result = maxSlidingWindow(nums, k);

    std::cout << "Maximum values in each sliding window: ";
    for (int val : result) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
