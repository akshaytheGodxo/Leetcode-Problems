#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        int n = s.size();
        map<char, int> apper;
        vector<bool> visited(26, false);
        for (auto i : s)
        {
            apper[i]++;
        }
        stack<char> st;
        st.push(s[0]);
        for (int i = 1; i < s.size(); i++)
        {
            apper[s[i]]--;
            if (visited[s[i] - 'a'])
                continue;

            char to = st.top();
            cout << to << " " << apper[to] << "\n";
            while (!st.empty() && st.top() > s[i] && apper[st.top()] > 0)
            {
                visited[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(s[i]);
            visited[s[i] - 'a'] = true;
            
        }
        string res = "";
        while (!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main()
{
    Solution st;
    string s;
    cin >> s;
    cout << st.removeDuplicateLetters(s);
    return 0;
}