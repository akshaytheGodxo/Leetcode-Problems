#include <bits/stdc++.h>

using namespace std;

class NumArray
{

public:
    vector<int> t;
    vector<int> k;
    NumArray(vector<int> &nums)
    {
        k = nums;
    }

    void update(int index, int val)
    {
    }

    int sumRange(int left, int right)
    {
    }

private:
    void buildtree(int i, int l, int r)
    {
        if (l == r)
        {
            t[i] = k[r];
            return;
        }

        int m = (l + r) / 2;
        buildtree(2 * i + 1, l, m);
        buildtree(2 * i + 2, m + 1, r);
        t[i] = t[2 * i + 1] + t[2 * i + 2];
    }
    int query(int i, int l, int r, int ql, int qr)
    {
        if (qr < l || ql > r)
            return 0;
        if (ql <= l && r <= qr)
            return t[i];

        int m = (l + r) / 2;
        return query(2 * i + 1, l, m, ql, qr) +
               query(2 * i + 2, m + 1, r, ql, qr);
    }

    void updatetree(int idx, int val, int i, int l, int r)
    {
        if (l == r)
        {
            t[i] = val;
            k[idx] = val;
            return;
        }

        int m = (l + r) / 2;
        if (idx <= m)
        {
            updatetree(idx, val, 2 * i + 1, l, m);
        }
        else
        {
            updatetree(idx, val, 2 * i + 2, m + 1, r);
        }
        t[i] = t[2 * i + 1] + t[2 * i + 2];
    }
};

int main()
{
}