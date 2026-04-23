#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstStableIndex(vector<int> &nums, int k) {
        priority_queue<int> maxi; // left max
        priority_queue<int, vector<int>, greater<int>> mini; 
        unordered_map<int, int> nmap; 

        for (int x : nums) mini.push(x);

        int n = nums.size();

        for (int i = 0; i < n; i++) {
            nmap[nums[i]]++;

            while (!mini.empty() && nmap[mini.top()] > 0) {
                nmap[mini.top()]--;
                mini.pop();
            }

            int left = maxi.empty() ? nums[i] : maxi.top();
            int right = mini.empty() ? nums[i] : mini.top();

            if (left - right <= k) return i;

  
            maxi.push(nums[i]);
        }

        return -1;
    }
};
int main()
{
    Solution solution;

    return 0;
}