#include <iostream>

using namespace std;

class Solution {
public:
    int maxDiff(int num) {
        string n1 = to_string(num);
        string n2 = to_string(num);

        char c1 = n1[0];

        

        for (int i = 0;i < n1.size();i++) {
            if (n1[i] == c1) {
                n1[i] = '9';
            }
        }
        bool chk = n2[0] <= '1' ? true : false;
        char c2 = n2[0];
        if (chk) {
            for (int i = 0;i < n2.size();i++) {
                if (n2[i] != '0' && n2[i] != '1' && n2[i] == c2) {
                    n2[i] = '0';
                }
            }
        } else {
            for (int i = 0;i < n2.size();i++) {
                if (n2[i] == c2) {
                    n2[i] = '1';
                }
            }
        }

        int num1 = stoi(n1);
        int num2 = stoi(n2);

        return num1 - num2;

    }
};


int main() {
    Solution s;
    int num;
    cin >> num;
    int ans = s.maxDiff(num);
    cout << ans << "\n";
    return EXIT_SUCCESS;    
}