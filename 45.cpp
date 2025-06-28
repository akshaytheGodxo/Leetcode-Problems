#include <iostream>
#include <vector>

using namespace std;

class Solution {

public:
  int searchRange(vector<int> v, int start, int range) {
    if (range > v.size())
      return -1;

    int largest = v[start];
    int idx = start;
    for (int i = start; i <= start + range; i++) {
      if (v[i] > largest) {
        largest = v[i];
        idx = i;
      }
    }
    return idx;
  }

  int jump(vector<int> &nums) {
    int st = 0;
    int steps = 0;
    int n = nums.size();
    int i = 0;
    while (i < n - 1) {
      int jmp_range = nums[i];
      st = searchRange(nums, i, jmp_range);
      if (st == -1) {
        i = n - 1;
        steps++;
        break;
      }
      i = st;
      steps++;
    }
    return steps;
  }
};

int main() {
  vector<int> nums = {1, 1, 1, 1};
  Solution s;
  cout << s.jump(nums);
  return 0;
}
