#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        vector<vector<char>> v(numRows);
        if (numRows == 1 || numRows >= s.length()) {return s;}

        int idx = 0, d = 1;
        for (char c : s) {
            v[idx].push_back(c);
            if (idx == numRows - 1) {
                d = -1;
            } else if (idx == 0){
                d = 1;
            }

            idx += d;
        }

        string ans;
        for (const auto& i : v) {
            for (char c : i) {
                ans += c;
            }
        }
        return ans;
    }
};


int main() {
    Solution sol;
    string s;
    int numRows;
    cin >> s >> numRows;
    cout << sol.convert(s, numRows);
    return 0;
}