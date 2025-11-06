#include <bits/stdc++.h>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(0);

int main()
{
	fastIO
	int t;
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n >> x;
		vector<int> arr(n, 0);
		for (int i=0;i<n;i++) {
			cin >> arr[i];
		}
		sort(arr.begin(), arr.end());
		reverse(arr.begin(), arr.end());
		int res = 0;
		for (int i=0, cnt=1;i<n;i++,cnt++) {
			if (arr[i] * cnt >= x) {
				res++;
				cnt=0;
			}
		}

		cout << res << "\n";

	}

	return 0;
}