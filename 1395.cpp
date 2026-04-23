#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> ra;
    vector<int> tree;
    int numTeams(vector<int> &rating) {
        int n=rating.size();
        int x = *max_element(rating.begin(), rating.end());
        tree = vector<int>(4*x, 0);
        ra = rating;
        vector<int> left;
        vector<int> right;
        for (int i=0;i<n;i++) {
            int cnt = query(0, 1, x, 1, rating[i]-1);
            left.push_back(cnt);
            update(rating[i], 1, 0, 1, x);
        }

        tree = vector<int>(4*x, 0);
        for (int i=n-1;i>=0;i--) {
            int cnt = query(0, 1, x, rating[i]+1, x);        
            right.push_back(cnt);
            update(rating[i], 1, 0, 1, x);
        }

        reverse(right.begin(), right.end());

        int ans = 0;

        for (int j=0;j<n;j++) {
            int left_greater = j- left[j];
            int right_smaller = (n-1-j) - right[j];

            ans += left[j] * right[j];
            ans += left_greater * right_smaller;
        }

        return ans;
    }


    int query(int i, int l, int r, int ql, int qr) {
        if (qr < l || ql > r) {
            return 0;
        }

        if (ql <= l && r <= qr) {
            return tree[i];
        }

        int m = (l + r)/2;
        return query(2*i+1, l, m, ql, qr) + query(2*i+2, m+1, r, ql, qr);
    }

    void update(int idx, int val, int i, int l, int r) {
        if (l == r) {
            tree[i] += val;
            return ;
        }

        int m = (l + r) / 2;
        if (idx <= m) {
            update(idx, val, 2*i+1, l, m);
        } else {
            update(idx, val, 2*i+2, m+1, r);
        }

        tree[i] = tree[2*i+1] + tree[2*i+2];
    }


    // void buildtree(int i, int l, int r) {
    //     if (l == r) {
    //         tree[i]= ra[r];
    //         return ;
    //     }

    //     int m = (l + r)/2;
    //     buildtree(2*i+1, l, m);
    //     buildtree(2*i+2, m+1, r);

    //     tree[i] = tree[2*i+1] + tree[2*i+2];
    // }

    
};

int main()
{
    Solution solution;

    return 0;
}