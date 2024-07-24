#include <bits/stdc++.h>
using namespace std;
// don't flip the subarray if it is all 1 

class Solution {
private:

public:
    int minKBitFlips(vector<int>& nums, int k) {
        deque<int> DQ;
        int left = 0;
        int flips = 0;
        int prefix_sum = 0;
        for (int i = 0;i < nums.size();i++) {
            // remove the elment which is outside of the winodw hehhe
            if (!DQ.empty() && DQ.front() == i)
                DQ.pop_front();

            if (DQ.size() % 2 == nums[i]) {

                if (i + k > nums.size()) // handling the case if the flipping is not possible
                    return -1;
                
                flips++;
                DQ.push_back(i+k);
            }
        }
        return flips;
    }
};

int main() {

    vector<int> nums = {0,1,0};
    int k = 1;
    Solution sol;
    int ans = sol.minKBitFlips(nums, k);
    cout << ans;
    return 0;
}