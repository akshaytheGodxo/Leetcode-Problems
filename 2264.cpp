#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string largestGoodInteger(string num) {
        string ans;
        string word;
        word += num[0];
        for (int i = 1;i < num.size();i++) {
            if (num[i] == num[i-1]) {
                word += num[i];
            } else {
                word = num[i];
            }
            cout << word << "\n";
            if (word.size() == 3) {
                if (word > ans) {
                    ans = word;
                }

                word = "";
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    string num;
    cin >> num;
    cout << s.largestGoodInteger(num);
    return EXIT_SUCCESS;
}