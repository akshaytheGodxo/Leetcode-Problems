#include <bits/stdc++.h>
using namespace std;


class NumArray {
public:
    vector<int> diff;
    int total=0;
    NumArray(vector<int>& nums) {
        for (auto i :nums) {
            total += i;
            diff.push_back(total);
        }
    }

    int sumRange(int left, int right) {
        if (left ==0) return diff[right];
        return diff[right] - diff[left-1];
    }
};


int main() {
		
	
}
