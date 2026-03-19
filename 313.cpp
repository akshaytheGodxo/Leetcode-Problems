#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    int nthSuperUglyNumber(int n, vector<int> &primes) {
        int s = primes.size();
        vector<int> multiples(s, 1);
        vector<int> dp(n+1, 0);
        dp[1] = 1;

        for (int i=1;i<=n;i++) {
            int minValue;
            int idx;
            for (int j=0;j<s;j++) {
                idx = multiples[j];
                int value = dp[idx] * primes[j];

                dp[i] = min(dp[i], value);
                minValue = dp[i];
            }

            for (int k=0;k<s;k++) {
                if (minValue == primes[k] * dp[idx]){
                    multiples[k]++;
                }
            }
        }

        return dp[n];
    }
};