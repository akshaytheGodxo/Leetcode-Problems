#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int recur(bool isAlice, int i, int m, vector<int> piles) {
        if (i == piles.size()) {
            return 0;
        }
        int total = 0;
        int res = isAlice == true ? 0 : INT_MAX;
        for (int x=1;x<2*m+1;x++) {
            if (x + i > piles.size()) break;
            total += piles[x + i - 1];

            if (isAlice) {
                res = max(res, total + recur(false, i+x, max(x, m), piles));
            } else {
                res = min(res, recur(true, i+x, max(x,m), piles));
            }
        }
        return res;
    }

    int stoneGameII(vector<int>& piles) {
        return recur(true, 0, 1, piles);
    }
};

int main(int argc, const char** argv) {
    vector<int> piles = {2,7,9,4,4};
    Solution s;
    cout << s.stoneGameII(piles);
    
    return 0;
}