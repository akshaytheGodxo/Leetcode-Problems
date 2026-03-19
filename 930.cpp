#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        int cnt =0;
        int pref = 0;
        queue<int> dq;
        for (int i=0;i<n;i++) {
            pref += nums[i];
            while (pref > goal) {
                pref -= dq.front();            
                dq.pop();
            }
            dq.push(nums[i]);
            if (pref == goal) cnt++;
        }
        return cnt;
    }
};

int main() {
    Solution s;

}