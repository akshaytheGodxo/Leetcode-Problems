#include <bits/stdc++.h>
using namespace std;



class Solution {
public: 
    string minWindow(string s, string t) {
        unordered_map<char, int> counter;

        for (auto i : t) {
            counter[i]++;
        }
        int sz=counter.size();
        int i=0, j=0;
        int n=s.size();
        int ans=INT_MAX;
        int st = 0;
        while (j < n) {
            if (counter.find(s[j]) != counter.end()) {
                counter[s[j]]--;
                if (counter[s[j]] == 0) {
                    sz--;
                }
            }
            
            while (sz == 0) {
                if (j - i+1 < ans) {
                    ans = j-i+1;
                    st=i;
                }
                if (counter.find(s[i]) != counter.end()) {
                    counter[s[i]]++;
                    if (counter[s[i]] > 0) {
                        sz++;
                    }
                }

                i++;
            }

            j++;
        }

        return ans == INT_MAX ? "" : s.substr(st, ans);

    }
};


int main(int argc, char const *argv[])
{
    Solution so;
    string s, t;
    cin >> s >> t;
    cout << so.minWindow(s, t);    
    return 0;
}
