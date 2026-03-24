#include <bits/stdc++.h>
using namespace std;

void sumTree(int l, int r, int i, vector<int> &segment, vector<int> nums) {
    if (l == r) {
        segment[i] = nums[r];
        return ;
    }

    int m = (l + r) / 2;
    sumTree(l, m, 2*i+1, segment, nums);
    sumTree(m+1, r, 2*i+2, segment, nums);
    segment[i] = segment[2*i+1] + segment[2*i+2];
}

void updatetree(int idx, int val, int i, int l, int r, vector<int> &segment, vector<int> nums) {
    if (l == r) {
        segment[i] = val;
        return ;
    }

    int m = (l + r)/2;
    if (idx <= m) {
        updatetree(idx, val, 2*i+1, l, m, segment, nums);
    } else {
        updatetree(idx, val, 2*i+2, m+1, r, segment, nums);
    }

    segment[i] = segment[2*i+1] + segment[2*i+2];
}
// 3 + 2 + 4 + 7
int main() { 
    vector<int> nums = {3, 1, 4, 7};
    int n=nums.size();
    vector<int> segmentTree(2*n, 0);
    sumTree(0, n-1, 0, segmentTree, nums);
    for (auto i : segmentTree) cout << i << " ";
    updatetree(1, 2, 0, 0, n-1, segmentTree, nums);
    cout << "Updated Tree\n";
    for (auto i : segmentTree) cout << i << " ";
    
    return 0;
}