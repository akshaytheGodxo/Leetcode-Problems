#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	bool isSpecial(char a, char b) {
		if (! (a >= 'a' && a <= 'z' && b >= 'a' && b <= 'z')) {
			return true;
		} 

		return false;
	}

	bool isNormal(char a, char b) {
	
		if (a >= 'a' && a <= 'z' && b >= 'a' && b <= 'z') {
			return true;
		} 

		return false;

	}

    string reverseByType(string s) {
        int ch = s.size() - 1, ed = s.size() - 1;

		int n = s.size();
		int i=0;

		while (i < s.size() / 2) {
			if (isSpecial(s[i], s[n - i - 1])) {
				swap(s[i], s[ch]);
				i++;
			}

			if (isNormal(s[i], s[n-i-1])) {
				swap(s[i], s[ed]);
				i++;
			}

			else {
				if (s[n-i-1] <= 'a' || s[n-i-1] >= 'z') {
					ch = n-i-1;
				} else {
					
				}
			}
			
		}
    }
};


int main() {

	Solution st;

	string s;

	cin >> s;

	cout << st.reverseByType(s);
	return 0;
}
