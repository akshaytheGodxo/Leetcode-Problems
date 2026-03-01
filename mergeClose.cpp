#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    string mergeCharacters(string s, int k) {
        int cnt = 0;
        string ans = "";
        map<char, int> index;
        for (int i=s.size()-1;i>=0;i--) {
            index[s[i]] = i;
        }
        for (int i=0;i<s.size();i++) {
            int idx = index[s[i]];
            if (i - cnt - idx > k || i == idx) {
                ans += s[i]; 
            } else {
                if (i != idx) {
                    
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    string st;
    int k;
    cin >> st >> k;
    cout << s.mergeCharacters(st, k);
    return 0;
}