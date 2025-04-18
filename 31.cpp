#include <bits/stdc++.h>
using namespace std;


void nextPermutation(vector<int>& nums) {
    int i=nums.size()-1;
    //findin the smallest
    while (i > 0 && nums[i-1] >= nums[i]) {
        i--;
    }

    if (i == 0) {
        reverse(nums.begin(), nums.end());
        return ;
    } 
    // finding the next largest digit possible
    int j = nums.size() - 1;
    while (j >= 1 && nums[j] <= nums[i-1]) {
        j--;
    }

    swap(nums[i-1], nums[j]);
    reverse(nums.begin()+i, nums.end());
}
int main() {
    vector<int> nums = {1,2,3};
    nextPermutation(nums);
    return 0;
}