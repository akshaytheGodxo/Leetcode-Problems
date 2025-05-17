#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



class Solution {
public:
    void solve(int i, int sum,int count, vector<int>& nums, vector<int>& arr, int goal) {
        if (sum == goal) {
            arr.push_back(count);
            return ;
        }

        if (sum > goal) sum -= nums[i];
        if (sum <= goal) sum += nums[i]; 
        count ++;
        solve(i++, sum, count, nums, arr, goal);
        count--;

    }

    int minimumOperations(vector<int>& nums, int start, int goal) {
        vector<int> ans;
        solve(0, start, 0, nums, ans, goal);
        sort(ans.begin(), ans.end());
        return ans[0];
    }
};

int main() {
    Solution solution;
    int start, goal;
    int size;
    std::vector<int> nums;

    for (int i = 0;i < size;i++) {
        int k;
        std::cin >> k;
        nums.push_back(k);
    }

    int ans = solution.minimumOperations(nums, start, goal);
    std::cout << ans << "\n";
    return EXIT_SUCCESS;
}