#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        map<string, int> m1;
        map<string, int> m2;
        for (int i = 0;i < bannedWords.size();i++) {
            int count = 1;
            m1[bannedWords[i]] += count; 
        }
        
        for (auto i : message) {
            int count = 1;
            m2[i] += count; 
        }   
        int total_value = 0;
        for (auto i : m2) {
            int v = m1[i.first];
            if (v != 0) {
                total_value += i.second;
            } 

            if (total_value >= 2)
                return true;
        }

        if (total_value >= 2)
            return true;

        return false;
    }
};


int main() {
    vector<string> message = {"s","a","aj","ps","h","ou","e","i","x"};
    vector<string> bannedWords = {"j","a","b","fa","z","a","no","ih","nq"};
    Solution s;
    bool ans = s.reportSpam(message, bannedWords);
    cout << ans << endl;
    return 0;
}