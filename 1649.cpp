// using policy based data structures

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
#include <iostream>
#include <vector>

using namespace __gnu_pbds;
using namespace std;
// this mf right here is the policy based data structure
/*
this data struct can be used in advanced competitive programming for the insertion and removal of element in an ordered maps/sets
Uses of this datastructure:
1. Order Statistics
2. Ranking of the elements

*/
// less_equal allows for duplicate elements in a tree
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define mod 1000000007;
class Solution {
private: 
	int strictly_less_than(ordered_set &os, int val) {
		return os.order_of_key(val);
		// returns the no. of values less than
	}
	int strictly_greater_than(ordered_set &os, int val) {
		return os.size() - os.order_of_key(val+1);
	}
public:
	int createSortedArray(vector<int>& instructions) {
		int n = instructions.size();
		int cost = 0;
		ordered_set os;
		for (auto &val:instructions) {
			cost = (cost + min(strictly_less_than(os, val), strictly_greater_than(os, val))) % mod;
			os.insert(val);
		}	

		return cost;
	}
};

// Define ordered set

int main() {
	ordered_set os;
	vector<int> instructions = {1, 5, 6, 2};
	Solution sol;
	int ans = sol.createSortedArray(instructions);
	cout << ans << endl;
	return 0;
}