#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> segmentTree;
    void buildTree(int i, int l, int r, vector<int> nums) {
        if (l == r) {
            segmentTree[i] = nums[l];
            return ;
        }

        int m=(l+r)/2;
        buildTree(2*i+1, l, m, nums);
        buildTree(2*i+2, m+1, r, nums);
        segmentTree[i] = segmentTree[2*i+1] + segmentTree[2*i+2];
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        segmentTree = vector<int>(4*n, 0);
        buildTree(0,0,n-1, nums);

        
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums={5,2,6,1};
    vector<int> res = s.countSmaller(nums);
    for (auto i : res) cout << i << " ";
    return 0;
}
