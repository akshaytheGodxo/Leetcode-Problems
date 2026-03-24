#include <bits/stdc++.h>
using namespace std;


int recur(vector<int> &stones, int sum, int st, int ed) {
    if (st == stones.size()) return 0;
    if (ed - st == 0) return 0;

    int res = 0;
    int curr = 0;
    for (int i=st;i<ed;i++) {
        curr += stones[i];
        int l = curr;
        int r = sum - curr;
        if (l < r) {
            res = max(res, l + recur(stones, l, st, i+1));
        } else {
            res = max(res, r + recur(stones, r, i+1, ed));
        }
    }
    return res;

}

int stoneGameV(vector<int> &stones) {
    int alice = 0;
    int su = 0;
    for (auto i : stones) su += i;
    int ans = recur(stones, su, 0, stones.size());
    return ans;
}

int main() {
    vector<int> stones = {6,2,3};
    cout << stoneGameV(stones);
    return 0;
}