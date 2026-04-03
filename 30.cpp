#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)    {
        map<string, int> count;
        map<string, int> curr;
        int maxi = INT_MIN;
        for (auto i:words) {
            count[i]++;
            maxi = max(maxi, i.size());
        }
        int n=s.size();
        string last = "";
        for (int i=0;i<n;i++) {
            last += s[i];
            auto it = count.find(last);
            if (it != count.end()) {
                
            } else {
                if (last.size() >= maxi) {
                    last = "";
                }
            }
        }

    }
};
int main()
{
    Solution solution;

    string s = "barfoothefoobarman";
    vector<string> words = {"foo", "bar"};

    vector<int> ans = solution.findSubstring(s, words);

    return 0;
}