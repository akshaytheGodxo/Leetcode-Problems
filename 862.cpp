#include <iostream>
#include <vector>
#include <deque>
#include <climits>

using namespace std;

int shortestSubarray(vector<int>& nums, int k) {
    int n = nums.size();
    vector<long long> prefix_sum(n + 1, 0);

    // Calculate the prefix sum
    for (int i = 0; i < n; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + nums[i];
    }

    deque<int> deque_indices;
    int min_length = INT_MAX;

    for (int i = 0; i <= n; ++i) {
        // Ensure the subarray sum is at least k
        while (!deque_indices.empty() && prefix_sum[i] - prefix_sum[deque_indices.front()] >= k) {
            min_length = min(min_length, i - deque_indices.front());
            deque_indices.pop_front();
        }

        // Maintain a decreasing order of prefix sums
        while (!deque_indices.empty() && prefix_sum[i] <= prefix_sum[deque_indices.back()]) {
            deque_indices.pop_back();
        }

        deque_indices.push_back(i);
    }

    return (min_length == INT_MAX) ? -1 : min_length;
}

int main() {
    vector<int> nums1 = {1};
    int k1 = 1;
    cout << shortestSubarray(nums1, k1) << endl;  // Output: 1

    vector<int> nums2 = {1, 2};
    int k2 = 4;
    cout << shortestSubarray(nums2, k2) << endl;  // Output: -1

    vector<int> nums3 = {2, -1, 2};
    int k3 = 3;
    cout << shortestSubarray(nums3, k3) << endl;  // Output: 3

    return 0;
}
