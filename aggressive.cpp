#include <bits/stdc++.h>
using namespace std;




int main() {

	int t;
	cin >> t;
	int n, c;
	for (int i = 0;i < t;i++) {
		cin >> n >> c;
		int s;
		vector<int> stallLocation;
		for (int j = 0;j < n;j++) {
			cin >> s;
			stallLocation.push_back(s);
		}
		int min_distance = INT_MAX;
		int l = 0;
		int r = stallLocation.size() - 1;
		while (l < r) {
			int m = l + (r - l) / 2;
			min_distance = abs(r - l);
			if (m < min_distance) {
				m = min_distance;
				cout << m << "\n";
			}
			else if (m > min_distance){
				r = m - 1;
			}
			l++;
		}
	}

	return 0;
}