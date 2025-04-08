#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        // equation = min(lh, rh) - h[i];
        int left_height = 0;
        int right_height = 0;
        int total_water = 0;
        int n=height.size();
        for (int i = 1;i<n-1;i++) {
        	left_height = *max_element(height.begin(), height.begin() + i);
        	right_height = *max_element(height.begin() + i+1, height.end());
        	int trapped_water = min(left_height, right_height) - height[i];
        	if (trapped_water > 0)
        		total_water += trapped_water;
        }

        return total_water;

    }
};

class Solution {
public:
	int trap(vector<int>& height) {
		// two pointer approach
		int n = height.size();
		int rightPtr = n-1;
		int leftPtr = 0;
		int left_height = height[leftPtr];
		int right_height = height[rightPtr];
		int total = 0;
		while (leftPtr < rightPtr) {
			if (left_height < right_height) {
				leftPtr++;
				// calculate max btw current left and the leftptr 
				left_height = max(left_height, height[leftPtr]);
				total += left_height - height[leftPtr];
			} else {
				rightPtr--;
				right_height = max(right_height, height[rightPtr]);
				total += right_height - height[rightPtr];
			}
		}

		return total;
	}
};


int main() {
	vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
	Solution sol;
	cout << sol.trap(height);
	return 0;
}