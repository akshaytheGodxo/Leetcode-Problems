#include <bits/stdc++.h>

using namespace std;
// asds
class Solution {
    public:
        int equalSubstring(string s, string t, int maxCost) {
            int n = s.size();
            int maxLen = 0;
            int start = 0;
            int currCost = 0;
            for (int i = 0;i < n;i++) {
                currCost += abs(s[i] - t[i]);

                // agar value zyada aa jaye to left se kam kar do

                while (currCost > maxCost) {
                    currCost -= abs(s[start] - t[start]);
                    start++;
                }

                maxLen = max(maxLen, i - start + 1);
            }

            return maxLen;
        }
    };


int main() {

    Solution sol;
    string s;
    string t;
    cin >> s >> t;
    int maxCost;
    cin >> maxCost;
    cout << sol.equalSubstring(s, t, maxCost);

    return EXIT_SUCCESS;

}