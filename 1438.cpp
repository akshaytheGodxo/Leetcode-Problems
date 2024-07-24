#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int longestSubarray(vector<int> &nums, int limit)
    {
        deque<int> MinWindow;
        deque<int> MaxWindow;
        int maxLength = 0;
        int left = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            // int diff = abs(nums[MinWindow.front()] - nums[MaxWindow.front()]); // ye basically dono deques ke front element ka difference hai

            while (!MinWindow.empty() && nums[MinWindow.back()] >= nums[i])
            {
                MinWindow.pop_back(); // hum yaha par last ke element ko current nums ke element se compare kara rahe hai and agar current element deque ke last element se bada hai to wo hat jaega deque se
            }
            MinWindow.push_back(i);
            while (!MaxWindow.empty() && nums[MaxWindow.back()] <= nums[i])
            {
                MaxWindow.pop_back(); // opposite of what we did just before
            }

            MaxWindow.push_back(i); // dono deques me current index ghused do
            while (abs(nums[MinWindow.front()] - nums[MaxWindow.front()]) > limit)
            {
                left += 1;
                // left basically ek border ki tarah kaam kar raha hai to agar koi bhi index agar left se kam hai to matlab wo bahar hai sliding window ke to usko nikaal do deque se
                // agar difference jyada ho jae to window ko left se kam kar do
                if (MinWindow.front() < left)
                    MinWindow.pop_front();
                if (MaxWindow.front() < left)
                    MaxWindow.pop_front();
            }

            maxLength = max(maxLength, i - left + 1);
        }
        return maxLength;
    }
};

int main()
{
    vector<int> nums = {10, 1, 2, 4, 7, 2};
    int limit = 5;
    Solution sol;
    int ans = sol.longestSubarray(nums, limit);
    cout << ans;
    return 0;
}