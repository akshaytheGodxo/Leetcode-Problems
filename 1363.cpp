#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string largestMultipleOfThree(vector<int> &digits)
    {
        vector<int> non_divisibles;
        vector<int> divisibles;
        int total = 0;
        for (auto i : digits)
        {
            if (i % 3 == 0)
                divisibles.push_back(i);
            else
            {
                non_divisibles.push_back(i);
            }
        }
        vector<pair<int, int>> rem1, rem2;

        for (int i = 0; i < digits.size(); i++)
        {
            total += digits[i];
            if (digits[i] % 3 == 1)
                rem1.push_back({digits[i], i});
            else if (digits[i] % 3 == 2)
                rem2.push_back({digits[i], i});
        }

        sort(rem1.begin(), rem1.end());
        sort(rem2.begin(), rem2.end());

        vector<bool> remove(digits.size(), false);

        if (total % 3 == 1)
        {
            int option1 = INT_MAX, option2 = INT_MAX;

            if (rem1.size() >= 1)
                option1 = rem1[0].first;

            if (rem2.size() >= 2)
                option2 = rem2[0].first + rem2[1].first;

            if (option1 <= option2)
            {
                if (option1 == INT_MAX)
                    return "{}";
                remove[rem1[0].second] = true;
            }
            else
            {
                if (option2 == INT_MAX)
                    return "{}";
                remove[rem2[0].second] = true;
                remove[rem2[1].second] = true;
            }
        }
        else if (total % 3 == 2)
        {
            int option1 = INT_MAX, option2 = INT_MAX;

            if (rem2.size() >= 1)
                option1 = rem2[0].first;

            if (rem1.size() >= 2)
                option2 = rem1[0].first + rem1[1].first;

            if (option1 <= option2)
            {
                if (option1 == INT_MAX)
                    return "{}";
                remove[rem2[0].second] = true;
            }
            else
            {
                if (option2 == INT_MAX)
                    return "{}";
                remove[rem1[0].second] = true;
                remove[rem1[1].second] = true;
            }
        }

        vector<int> result;
        for (int i = 0; i < digits.size(); i++)
        {
            if (!remove[i])
                result.push_back(digits[i]);
        }

        for (auto i : result) cout << i << " ";
        sort(result.begin(), result.end(), greater<int>());
        string ans = "";
        for (auto i : result) ans += to_string(i);
        if (ans.size() > 0 && ans[0] == '0') return "0";
        return ans;
    }
};

int main() {
    Solution st;
    vector<int> digits = {8,6,7,1,0};
    st.largestMultipleOfThree(digits);
}