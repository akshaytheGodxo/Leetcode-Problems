#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int output = 0;
        for (auto i : operations) {
            if (i == "--X" || i == "X--") {
                output--;
            } else {
                output++;
            }
        }
        return output;
    }
};

int main() {
    Solution s;
    vector<string> operations = {"++X","++X","X++"};
    cout << s.finalValueAfterOperations(operations);
    return 0;
}