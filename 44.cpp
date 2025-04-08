#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

class Solution { 
    public:
        bool isMatch(string s, string p) {
            bool ans = false;
            map<char, char> m;
            for (int i = 0;i < s.size();i++) {
                for (int j = 0;j < p.size();j++) {
                    if (s[i] == p[j]) {
                        ans = true;
                        break;
                    }
                }
                if (!ans) {
                    return false;
                }
            }

            return ans;

        }
    };


int main() {
    Solution s;
    string str1, str2;
    cin >> str1 >> str2;
    cout << s.isMatch(str1, str2) << endl;
    return 0;
}