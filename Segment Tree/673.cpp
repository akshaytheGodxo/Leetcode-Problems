#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> tree;

    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        int x = *max_element(nums.begin(), nums.end());

        tree = vector<int> (4*x, 0);
        vector<int> left;
        int min = *min_element(nums.begin(), nums.end());
        for (int i=0;i<n;i++) {
            int cnt = query(0, 1, x, min, nums[i]-1);
            left.push_back(cnt);
            update(nums[i], 1, 0, min, x);
        }

        return *max_element(left.begin(), left.end());
    }

    int query(int i, int l, int r, int ql, int qr) {
        if (qr < l || ql > r) {
            return 0;
        }

        if (ql <=l && r <= qr) {
            return tree[i];
        }


        int m = (r + l) / 2;

        return query(2*i + 1, l, m, ql, qr) + query(2*i+2, m+1, r, ql, qr);
    }

    void update(int idx, int val, int i, int l, int r) {
        if (l == r) {
            tree[i] += val;
            return ;
        }

        int m = (l + r)/2;
        if (idx <=m ){ 
            update(idx, val, 2*i+1, l, m);
        } else {
            update(idx, val, 2*i+2, m+1, r);
        }

        tree[i] = tree[2*i+1] + tree[2*i+2];
    }

};

int main() {
    Solution solution;
    
    return 0;
}