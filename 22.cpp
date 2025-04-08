#include <bits/stdc++.h>

using namespace std;

void solve(int leftCount, int rightCount, int n, vector<char>& output, vector<string>** ans) {
    if (leftCount >= n && rightCount >= n) {
            string outputStr(output.begin(), output.end());
            ans.push_back(outputStr);    }

    if (leftCount < n) {
        output.push_back('(');
        solve(leftCount + 1, rightCount, n, output, ans);
        output.pop_back();
    }
    if (rightCount < leftCount) {
        output.push_back(')');
        solve(leftCount, rightCount + 1, n, output, ans);
        output.pop_back();
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> ans;
    vector<char> output;

    solve(0, 0, n, output, ans);
    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<string> ans = generateParenthesis(n);
    
    for (auto i : ans) {
        cout << i << " ";
    }
    return 0;
}