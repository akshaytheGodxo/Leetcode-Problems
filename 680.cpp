#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  bool isPalinderome(string s, int i, int j) {
    while (i < j) {
      if (s[i] != s[j]) {
        return false;
      }
      i++;
      j--;
    }

    return true;
  }

public:
  bool validPalindrome(string s) {
    int i = 0, j = s.size() - 1;

    while (i < j) {
      if (s[i] != s[j]) {
        // ya to left skip karke dekho ya fir right ko
        return isPalinderome(s, i + 1, j) || isPalinderome(s, i, j - 1);
      }

      i++;
      j--;
    }

    return true;
  }
};

int main() {
  string s;
  cin >> s;
  Solution sol;

  cout << sol.validPalindrome(s);
  return 0;
}
