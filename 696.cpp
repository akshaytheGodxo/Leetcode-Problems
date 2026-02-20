#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int countBinarySubstrings(string s) {
    int res = 0, cur = 1, pre = 0;
    int n = s.size();
    for (int i = 1; i < n; i++) {
      if (s[i] == s[i - 1]) {
        cur++;
      } else {
        res += min(cur, pre);
        pre = cur;
        cur = 1;
      }
    }

    return res + min(cur, pre);
  }
};

int main() {
  Solution st;

  string s;

  cin >> s;

  cout << st.countBinarySubstrings(s);

  return 0;
}
