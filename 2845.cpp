#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  long long countInterestingSubarrays(vector<int> &nums, int modulo, int k) {
    int n = nums.size();
    vector<int> count(n, 0);
    count[0] = 0;
    for (int i = 1; i < nums.size(); i++) {
      count[i] = count[i - 1] + (nums[i - 1] % modulo == k ? 1 : 0);
    }

    for (auto i : count) {
      cout << i << " ";
    }

    for (int i = 1; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if ((count[i] - count[j]) % modulo == k) {
          count[j] = (count[i] + modulo - k) % modulo;
        }
      }
    }
    for (auto i : count) {
      cout << i << " ";
    }

    return 0;
  }
};

int main() {
  Solution st;
  vector<int> nums = {3, 2, 4};
  int modulo = 2;
  int k = 1;

  cout << st.countInterestingSubarrays(nums, modulo, k);
  return 0;
}
