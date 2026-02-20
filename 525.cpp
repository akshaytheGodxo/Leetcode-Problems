#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int findMaxLength(vector<int>& nums) {
        int zc = 0, oc = 0;
        map<int, int> count;
        int n = nums.size();
        int ans = 0;
        for (int i=0;i<n;i++) {
            if (nums[i] == 0) zc++;
            else if (nums[i] == 1) oc++;

            auto find = count.find(oc - zc);
            if (find == count.end()) {
                count[oc - zc] = i;
            }

            if (oc == zc) {
                ans = oc + zc;
            } else {
                int idx = count[oc - zc];
                ans = max(ans, (i - idx ));
            }

        }

        return ans;

    }
};

int main(int argc, char const *argv[])
{
    Solution st;
    vector<int> nums = {0,1,1,1,1,1,0,0,0};
    cout << st.findMaxLength(nums);
    return 0;
}
