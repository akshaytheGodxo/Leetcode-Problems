#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // hume basically window ki size i - j <= k ki range me hi leke chalni hai agar iske bahar koi element jata hai to use simply pop kar do

        map<int, vector<int>> m;
        vector<int> resi;
        for (int i = 0;i < nums.size();++i) {
            int val = nums[i];
            resi = m[val];
            resi.push_back(i);
            m[val] = resi;
        } 
        
        // now we can just use sliding window in those vector's whose length is > 1
        for (auto x : m) {
            if (x.second.size() > 1) {
                for (int i = 0;i < x.second.size()-1;i++) {
                    int diff = abs(x.second[i] - x.second[i+1]);
                    if (diff <= k)
                        return true;
                }
            }
        }
        return false;
    }
};


int main() {
    Solution sol;
    vector<int> nums = {1,0,1,1};
    int k = 1;
    cout << sol.containsNearbyDuplicate(nums, k);
    return 0;
}