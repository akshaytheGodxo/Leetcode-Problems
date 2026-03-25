#include <bits/stdc++.h>
using namespace std;

class Solution {
public:


    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n=s.size();
        vector<int> changes(n, 0);
        for (int i=1;i<n;i++) {
            int len = i - 0 + 1;
            if (len % 2 != 0) {
                if (s[i] != s[0]) {
                    s[i] = s[i-1];
                } else {
                    s[i] = s[i-1] - 1;
                }
            } else {
                if (s[i] != s[0]) {
                    s[i] = s[i-1] + 1; 
                } else {
                    s[i] = s[i-1];
                }
            }
        }

        vector<bool> res;
        for (auto i : queries) {
            int st = i[0];
            int ed = i[1];
            int ch = i[2];
            if (changes[ed] - changes[st] <= ch) {
                res.push_back(true);            
            
            } else {
                res.push_back(false);
            }
        }
        return res;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;
    vector<vector<int>> queries;
    return 0;
}
