#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int reverseNum(int num) {
        int out = 0;
        while (num > 0) {
            int rem = num % 10;
            out = (out * 10) + rem;
            num /= 10;
        }
        return out;
    }

    int minMaxDifference(int num) {
        unordered_map<int, int> maxt;
        unordered_map<int, int> mint;
        string max_num = "";
        string min_num = "";
        string k = to_string(num);

        char z1 = 0;
        char z2 = 0;

        for (char i : k) {
            if (i != '9') {
                z1 = i;
                break;
            }
        }
        for (char i : k) {
            if (i != '0') {
                z2 = i;
                break;
            }
        }
        cout << z1 << " "<<  z2 << "\n";

        for (char i : k) {
            if (i == z1) {
                max_num += '9';
            } else {
                max_num += i;
            }
        }

        for (char i : k) {
            if (i == z2) {
                
                min_num += '0';
            } else {
                min_num += i;
            }
        }

        int mini = stoi(min_num);
        int maxi = stoi(max_num);

        cout << min_num << " " << max_num << "\n";
        int difference = maxi - mini;
        return difference;
    }
};


int main() {
    int n;
    cin >> n;
    Solution s;
    cout << s.minMaxDifference(n);
    return EXIT_SUCCESS;
}