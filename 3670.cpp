#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long maxProduct(vector<int> &nums)
    {      
        long long maxi = INT_MIN;

        int n=nums.size();
        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) {
                if (i != j) {
                    int op = nums[i] & nums[j];
                    if (op == 0) {
                        maxi = max(maxi,(long long) nums[i] * nums[j]);
                    }
                }
            }
        }
        return maxi;
    }
};
int main()
{
    Solution solution;
    vector<int> nums = {1,2,3,4,5,6,7};
    cout << solution.maxProduct(nums);
    return 0;
}