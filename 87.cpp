#include <bits/stdc++.h>

using namespace std;

void solve(string &s1, string &s2, bool &ans, int m) {
    if (s1.size() == 0 || s2.size() == 0) {
        return ;
    }

    if (s1 == s2) {
        ans = true;
        return ;
    }

    int n = s1.size();
    string x = s1.substr(0, m-1);
    string y = s1.substr(m, m+1);

    string a = x + y;
    string b = y + x;

    solve(a, s2, ans, m--);
    m++;
    solve(a, s2, ans, m--);
}

bool isScramble(string s1, string s2) {
    bool ans = false;
    int n = s1.size();
    solve(s1, s2, ans, n-1);
    return ans;
}


int main() {
    string s1, s2;
    cin >> s1 >> s2;

    cout << isScramble(s1, s2);
    return 0;
}