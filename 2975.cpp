#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    int maximizeSquareArea(int m, int n, vector<int> &hFences, vector<int> &vFences)
    {
        ll mod = 1e9 + 7;

        hFences.emplace(hFences.begin(), 1);
        hFences.emplace(hFences.end(), m);

        vFences.emplace(vFences.begin(), 1);
        vFences.emplace(vFences.end(), n);

        // for (auto i : hFences) cout << i << " ";

        unordered_set<int> hDis;
        for (int i = 0; i < hFences.size(); i++)
        {
            for (int j = 0; j < hFences.size(); j++)
            {
                if (i != j)
                {
                    int diff = abs(hFences[i] - hFences[j]);
                    hDis.insert(diff);
                }
            }
        }
        int maxi = -1;
        for (int i = 0; i < vFences.size(); i++)
        {
            for (int j = 0; j < vFences.size(); j++)
            {
                if (i != j)
                {
                    int diff = abs(vFences[i] - vFences[j]);
                    if (hDis.find(diff) != hDis.end())
                    {
                        maxi = max(maxi, diff);
                    }
                }
            }
        }

        return maxi == -1 ? -1 : (maxi * maxi) % mod;
    }
};

int main(int argc, const char **argv)
{
    Solution st;

    vector<int> hFences = {2, 3};
    vector<int> vFences = {2};

    st.maximizeSquareArea(4, 3, hFences, vFences);

    return 0;
}