#include <iostream>
#include <algorithm>
using namespace std;
string convertToTitle(int columnNumber) {
    string ans = "";



    if (columnNumber < 26) {

        char x = (char) columnNumber + 64;
        ans.push_back(x);
        return ans;
    }
    else {
        // 27 - 26 = 01 + 64;
        // 48 - 26 = 22 + 64 -> AV;
        // 701 - 26 = ????????
        int n = columnNumber;
        while (n > 0) {
            char rem = char ((n-1)%26 + 65);
            ans += rem;
            n = (n - 1)/ 26;
        }

        
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main() {

    string s;
    int n;
    cin >> n;
    cout << convertToTitle(n);
    return 0;
}