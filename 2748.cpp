#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isCoPrime(int n1, int n2) {
        int ans = __gcd(n1, n2);
        return ans == 1 ? true : false; 


    }
    int countBeautifulPairs(vector<int>& nums) {
        int i = 0, j = i+1;
        int n = nums.size();
        int cnt = 0;
        while (i < n-1 && j < n) {
            if (isCoPrime(nums[i], nums[j])) {
                // cout << "Pair: " << nums[i] << " " << nums[j] << "\n";

                cnt++;
                j++;
            } else {
                i++;
                j = i+1;
            }
        }
        if (isCoPrime(nums[n-2], nums[n-1])) cnt++;
        return cnt;
    }
};

int main() {
    Solution s;
    vector<int> nums = {2,5,1,4};
    cout << s.countBeautifulPairs(nums);
    return 0;
}