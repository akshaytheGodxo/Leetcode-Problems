#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> decrypt(vector<int>& code , int k) {
        int curr_sum = 0;
        vector<int> flag = code;
        if (k > 0) {
            for (int i = k; i>0;i--) {
                curr_sum += flag[i];
            }
            code[0] = curr_sum;
            for (int i = 1;i < code.size();i++) {
                curr_sum = curr_sum + flag[i-1] - flag[i];
                code[i] = curr_sum;
            }
        }
        if (k == 0) {
            for (int i = 0;i < code.size();i++) {
                code[i] = 0;
            }
        }
        else if (k < 0) {
            
        }
        return code;
    }
};  

int main() {
    vector<int> code = {5,7,1,4};
    int k = 3;
    Solution sol;
    vector<int> decrypted_arr = sol.decrypt(code, k);
    for (auto i : decrypted_arr) cout << i << " ";
    return 0;
}