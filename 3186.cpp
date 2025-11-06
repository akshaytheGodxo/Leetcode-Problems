#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution
{
public:
    

    ll  maximumTotalDamage(vector<int> &power)
    {
        ll  dp[100001] = {0}, max_dp = 0;
        sort(begin(power), end(power));
        for (int i = 0, j = 0; i < power.size(); ++i)
            if (power[i] == power[max(0, i - 1)])
                dp[i + 1] = power[i] + dp[i];
            else
            {
                while (power[j] + 2 < power[i])
                    max_dp = max(max_dp, dp[++j]);
                dp[i + 1] = power[i] + max_dp;
            }
        return *max_element(begin(dp), begin(dp) + power.size() + 1);
    }
};

int main()
{
    Solution s;
    vector<int> power = {7, 1, 6, 6};
    ll ans = s.maximumTotalDamage(power);
    cout << ans << "\n";
    return 0;
}