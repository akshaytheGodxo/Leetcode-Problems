#include <bits/stdc++.h>
using namespace std;

int calcSum(vector<int> nums) {
    int s = 0;
    for (auto i : nums) s += i;
    return s;
}

int pivotIndex(vector<int>& nums) {
    if (nums.size() == 1) return -1;
    int totalSum = calcSum(nums);
    int leftSum = 0;
    int rightSum = 0;
    int ans = -1;
    
    for (int i = 0;i < nums.size();i++) {
        leftSum = 0;
        rightSum = 0;
        // calculate leftSum
        for (int j = 0;j < i;j++) {
            leftSum += nums[j];
        }
        for (int k = nums.size() - 1;k > i;k--) {
            rightSum += nums[k];
        }
        cout << leftSum << " " << rightSum << endl;
        if ((totalSum - leftSum )== (totalSum - rightSum)) {
            ans = i;
            break;
        }
    }

    return ans;
}
int main() {
    vector<int> nums = {-1, 2};
    cout << pivotIndex(nums);
    return 0;
}