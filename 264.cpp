#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <queue>
#include <vector>
#include <unordered_set>

using namespace std;


class Solution {
public:
    int nthUglyNumber(int n) {
        
		priority_queue<long, vector<long>, greater<long>> heap;
		unordered_set<ll> visited;
		vector<int> primes = {2, 3, 5};
		heap.push(1);
        visited.insert(1);
		ll curr;
		for (int i=0;i<n;i++) {
			curr = heap.top();
			heap.pop();
			for (int prime: primes) {
				ll n = curr * prime;

				if (visited.find(n) == visited.end()) {
					visited.insert(n);
					heap.push(n);
				}
			}
		}
		return (int)curr;
    }
};

int main() {
	Solution st;

	int n;
	cin >> n;


	cout << st.nthUglyNumber(n);

	return 0;
}
