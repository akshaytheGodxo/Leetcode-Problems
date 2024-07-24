/* Find Peak Element */
/*
    
    let peakEl = nums[0];
    let idx = 0;

    run a binarySearch loop

    if (nums[m] > peakEl) :
        peakEl = nums[m];
        idx = m;
        s = m + 1;
    else if nums[m] < peakEl
        e = m - 1;

*/

#include <bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int>& nums) {
    int n = nums.size();
    int s = 0;
    int e = n-1;
    while (s < e) {
        int m = s + (e - s) / 2;
        if (nums[m] < nums[m+1])
            s = m + 1;
        else
            e = m;
    }
    return s;

}

int main() {
    vector<int> nums = {1,2,3,1};
    cout << findPeakElement(nums) << endl;
    return 0;
}