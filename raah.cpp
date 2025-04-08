#include <bits/stdc++.h>
using namespace std;

int main() {
    map<char, int> m;
    m['I'] = 1;
    m['V'] = 5;
    m['X'] = 10;
    m['L'] = 50;
    m['C'] = 100;
    m['D'] = 500;
    m['M'] = 1000;

    string s;
    cin >> s;
    int total = 0;

    for (int i = 0; i < s.size(); i++) {
        if (i < s.size() - 1 && m[s[i]] < m[s[i + 1]]) {
            total -= m[s[i]];
        } else {
            total += m[s[i]];
        }
    }

    cout << total << endl;
    return 0;
}
