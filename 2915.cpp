#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
    public:
        void solve(int i,int steps, int n, int target, vector<int> arrayLength, vector<int> nums) {
            if (i == nums.size() - 1) {
                return ;
            }
            if (n == target) {
                arrayLength.push_back(steps);
                return ;
            }

            n += nums[i];
            steps++;
            solve(i++, steps, n, target, arrayLength, nums);
            steps--;
            n -= nums[i];

        }

        int lengthOfLongestSubsequence(vector<int>& nums, int target) {
            vector<int> array_lenght;
            solve(0, 0, 0, target, array_lenght, nums);

            sort(array_lenght.begin(), array_lenght.end());
            int ans = array_lenght[-1];
            return ans;
        }
};


int main() {
    Solution sol;
    vector<int> nums = {1,2,3,4,5};
    int target = 9;
    int ans = sol.lengthOfLongestSubsequence(nums, target);
    cout << ans << "\n";
    return 0;
}