#include <bits/stdc++.h>
using namespace std;
#define ll long long

unordered_map<ll, ll> dp;
ll solve(ll n)
{
    if (n == 0)
    {
        return 0;
    }

    if (dp.count(n))
        return dp[n];

    ll res = max(solve(n / 2) + solve(n / 3) + solve(n / 4), n);

    dp[n] = res;

    return res;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> boys(n);
    vector<int> girls(m);
    for (auto &x : boys)
        cin >> x;
    for (auto &x : girls)
        cin >> x;

    sort(boys.begin(), boys.end(), greater<>());
    sort(girls.begin(), girls.end(), greater<>());
    int sum = 0;
    for (int i=0;i<n;i++) {
        sum += abs(girls[i] - boys[i]);
    }

    cout << sum;

    return 0;
}