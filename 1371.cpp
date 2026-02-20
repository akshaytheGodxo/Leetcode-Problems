#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int numSubarrayProductLessThanK(vector<int> &nums, int k) {
    int count = 0;
    stack<int> st;
    queue<int> ntt;
    long long prod = 1;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] < k) {
        count++;
        ntt.push(nums[i]);
      }

      while (prod * nums[i] >= k) {
        prod /= ntt.front();
        ntt.pop();
      }
      if (prod * nums[i] < k)
        count++;
    }

    return count;
  }
};

int main() {
  Solution st;

  string s;
  cin >> s;
  vector<int> nums = {10, 5, 2, 6};
  cout << st.numSubarrayProductLessThanK(nums, 100);
  return 0;
}
