#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastIO ios_base::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

// shortcuts
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

// loops
#define rep(i,a,b) for(int i=(a); i<(b); i++)
#define rrep(i,a,b) for(int i=(a); i>=(b); i--)

// debug (comment out in contest)
#define debug(x) cerr << #x << " = " << x << endl;

// input helpers
#define input_vec(v) for (auto &x : v) cin >> x;

void solve() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    input_vec(a);

    vector<int> pref(n, 0);
    pref[0] = a[0];

    for (int i=1;i<n;i++) {
        pref[i] = pref[i-1] + a[i];
    }
    int total = pref[n-1];
    int k = 0;
    while (k != n-1) {
        int m = *max_element(a.begin(), a.end() - k);
        int curr = total - pref[n - k - 2];
        curr -= a[n-k-1];
        curr += m;
        cout << curr << " ";
        k++;
    }

    cout << total << endl;
}

int32_t main() {
    fastIO
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}