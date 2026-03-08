#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minFlips(string s) {
        int n = s.size();

        s += s;

        string s1, s2;

        for (int i=0;i < s.size();i++) {
            s1 += i % 2 ? '0' : '1';
            s2 += i % 2 ? '1' : '0';
        }
    }
};


int main() {
    Solution s;
    string st;
    cin >> st;
    cout << s.minFlips(st);
    return 0;
}