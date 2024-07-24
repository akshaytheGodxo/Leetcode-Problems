#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans = 0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<=nums[i-1]){
                ans += nums[i-1]-nums[i]+1;
                nums[i]= nums[i-1]+1;
            }
        }
        return ans;
    }

};

// 1 1 2 2 3 7 -> 1 + 
int main() {
    Solution solution;
    vector<int> nums = {2,2,2,2,0}; // 0 2 2 2 2
    cout << solution.minIncrementForUnique(nums);
    return 0;
}