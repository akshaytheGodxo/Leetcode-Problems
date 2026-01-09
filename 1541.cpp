#include <bits/stdc++.h>

using namespace std;

void insertIntoStack(stack<char> &st, char ch, int &ans) {
    if (ch == '(') {
        st.push(ch);
        ans += 2;
    }  else {
        st.push(ch);
    }
}

int minInsertions(string s) {
    stack<char> st;
    int total = 0;

    for (auto i : s) {
        if (i == '(') {
            if (st.empty()) {
                st.push(i);
            } else {
                if (st.top() == '(') {
                    st.push(i);
                } else {
                    total++;
                    st.pop();
                    st.pop();
                    st.push(i);
                }
            }
        } else {
            if (st.empty()) {
                total++;
                st.push('(');
                st.push(i);
            } else {
                if (st.top() == '(') {
                    st.push(i);
                } else {
                    st.pop();
                    st.pop();
                }
            }
        }

        
    }

    if (st.empty()) {
        return total;
    } else {
        while (!st.empty()) {
            if (st.top() == '(') {
                total += 2;
                st.pop();
            } else {
                total++;
                st.pop();
                st.pop();
            }
        }

        return total;
    }

}

int main() {
    string x;
    cin >> x;


    cout << minInsertions(x);
    return 0;
}