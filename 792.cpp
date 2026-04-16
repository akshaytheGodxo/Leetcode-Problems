#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // void solve() {
    // int x = 'z' - 'a';
    // cout << x << endl;
    // }
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<int> map(26, 0);
        for (auto i : s) {
            map[i-'a'] += 1;
        }

        for (auto i : words) {
            
        }
    }
};

int main() {
    Solution solution;
    solution.solve();
    return 0;
}