#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    char kthCharacter(long long k, vector<int>& operations) {
        string word = "a";

        for (int i = 0;i < operations.size();i++) {
            if (operations[i] == 0) {
                
            } else {

            }
        }
    }
};


int main() {
    Solution s;
    long long k = 5;
    cin >> k;
    vector<int> operations = {0, 0, 0};
    cout << s.kthCharacter(k, operations);
    return 0;
}