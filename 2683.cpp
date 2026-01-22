#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int xorr = derived[0];
        for (int i=1;i<derived.size();i++) {
            xorr = xorr ^ derived[i];
        }

        return xorr == 0 ? true : false;
    }
};

int main(int argc, char const *argv[]) {
    
    return 0;
}
