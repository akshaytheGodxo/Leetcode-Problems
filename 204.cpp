#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> prime(n + 1, true);
        for (int p = 2; p * p <= n; p++) {
            if (prime[p] == true) {

                for (int i = p * p; i <= n; i += p)
                    prime[i] = false;
            }
        }

        vector<int> res;
        for (int i = 2; i <= n; i++) {
            if (prime[i] == true) {
                res.push_back(i);
            }
        }
        for (auto i : res)
            cout << i << " ";
        return res.size();
    }
};