#include <bits/stdc++.h>
using namespace std;


int lengthOfLIS(vector<int>& nums) {
    int n=nums.size();
    int lastSum=0, lastValue = nums[n-1];
    vector<int> arr(n, 1);
    for (int i=n-1;i>=1;i--) {
        if (lastValue > nums[i-1]) {
            
        }
    }
    int maxi =  *max_element(arr.begin(), arr.end());
    return maxi;
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {7,7,7,7,7,7,7};
    cout << lengthOfLIS(nums);
    return 0;
}
