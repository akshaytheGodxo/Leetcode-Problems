#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int mex(vector<int> const &A)
    {
        set<int> b(A.begin(), A.end());

        int result = 0;
        while (b.count(result))
            ++result;
        return result;
    }

public:
    int findSmallestInteger(vector<int> &nums, int value)
    {
        sort(nums.begin(), nums.end());
        int inital = mex(nums);
        for (int i=0;i<nums.size();i++) {
            int me = mex(nums);
            if (nums[i]%value == me) {
                nums[i] = me;
            }
        }

        int final = mex(nums);
        return final;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {1, -10, 7, 13, 6, 8};
    int value = 5;
    Solution s;
    cout << s.findSmallestInteger(nums, value);
    return 0;
}
