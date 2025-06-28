#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int findContentChildren(vector<int> &g, vector<int> &s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int idx = 0;
    int children = 0;
    while (idx < s.size() && children < g.size()) {
      if (s[idx] >= g[children]) {
        children++;
      }

      idx++;
    }

    return children;
  }
};

int main() {

  vector<int> g = {1, 2, 3};

  vector<int> s = {1, 1};

  Solution sol;
  cout << sol.findContentChildren(g, s) << endl;

  return 0;
}
