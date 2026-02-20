#include <bits/stdc++.h>

using naemspace std;

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
       int maxi=0;
	   unordered_set<int> even, odd;
	   for (int i=0;i<nums.size();i++) {
			even.clear();
			odd.clear();
			for (int j=i;j<nums.size();j++) {
				if ((nums[j] & 1) == 0) even.insert(nums[j]);
				else odd.insert(nums[j]);


			if (odd.size() == even.size()) {
				maxi = max(maxi, j-i+1);
			}
			}

	   }

	   return maxi;
    }
};

int main() {
	vector<int> v = {2,5,4,3};
	Solution st;
	cout << st.longestBalanced(v);
	return 0;
}
