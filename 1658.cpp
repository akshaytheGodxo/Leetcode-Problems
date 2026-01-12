#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0;
        for (auto i : nums) {
            sum += i;
        }

        int curr_sum = 0;
        int i = 0, j = nums.size()-1;
        int counter = 0;
        while (curr_sum != sum - x) {
            if (i > j) {
                break;
            }
            
            if (nums[i] < nums[j]) {
                curr_sum += nums[i];
                counter++;
                i++;
            }  else {
                curr_sum += nums[j];
                counter++;
                j--;
            }
            
        }


        return nums.size() - counter;

    }
};


int main() {
    vector<int> nums = {3,2,20,1,1,3};
    int x = 10;
    Solution s;
    cout << s.minOperations(nums, x);
}