#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, m;
    cin >> n;
    
    cin >> m;

    vector<int> v(n), d(n);
    for (auto &x : v) cin >> x;
    for (auto &x : d) cin >> x;

    vector<int> tracker(n, 0);

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    

}