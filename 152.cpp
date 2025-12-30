#include <bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    int maxProduct(vector<int>& nums) {
        int maxProd = INT_MIN;
        int prod = 1;
        // left to right traversal
        for (int i=0;i<nums.size();i++) {
            prod *= nums[i];
            maxProd = max(prod, maxProd);
            if (prod == 0) {
                prod = 1;
            }
        }
        prod = 1;

        // right to left traversal
        for (int i=nums.size()-1;i>=0;i--) {
            prod *= nums[i];
            maxProd = max(maxProd, prod);
            if (prod == 0) prod = 1;
        }

        return maxProd;
    }
};
int main()
{
    Solution solution;
    vector<int> nums = {2, 2, -2, -2};
    cout <<"Ans: " << solution.maxProduct(nums);
    return 0;
}