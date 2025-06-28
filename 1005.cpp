#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
  int largestSumAfterKNegations(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end());
    int shortest = nums[0];
    int shortestIDX = 0;
    int sum = 0;

    while (k > 0) {
      if (shortest == 0) {
        k = 0;
      }
      nums[shortestIDX] = -nums[shortestIDX];
      if (nums[shortestIDX] > nums[shortestIDX + 1] &&
          shortestIDX < nums.size() - 1) {
        // updating the shortest number
        shortestIDX++;
        shortest = nums[shortestIDX];
        k--;
      } else {
        k--;
      }
    }

    for (auto i : nums) {
      sum += i;
    }

    return sum;
  }
};

int main() {
  vector<int> nums = {-2, 9, 9, 8, 4};
  int k = 5;
  Solution sol;
  cout << sol.largestSumAfterKNegations(nums, k);
  return 0;
}
