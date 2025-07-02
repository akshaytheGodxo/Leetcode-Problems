#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int possibleStringCount(string word) {
        int count = 1;
        for (int i = 1;i < word.size();i++) {
            if (word[i] == word[i-1]) {
                count++;
            }
        }

        return count;
    }
};

int main() {
    Solution s;
    string st;
    cin >> st;
    cout << s.possibleStringCount(st);
    return 0;
}