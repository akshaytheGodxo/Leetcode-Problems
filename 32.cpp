#include <iostream>
#include <stack>

using namespace std;
int longestValidParentheses(string s) {
	stack<int> st;
	for (int i=0;i<s.size();i++) {
		if (s[i] == '(') 
			st.push(i);
		else if (s[i] == ')') {
			if (st.empty() || s[st.top()] != '(') {
				st.push(i);
			}
			else {
				st.pop();
			}
		}
	}

	int end = s.size();
	int substr = 0;
	while (!st.empty()) {
		int idx = st.top();
		st.pop();
		substr = max(substr, end - idx - 1);
		end = idx;
	}
	substr = max(substr, end);
	return substr
}

int main() {
	string s;
	cin >> s;
	longestValidParentheses(s);
	return 0;
}