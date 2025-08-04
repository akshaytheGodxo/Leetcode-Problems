#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int ans = INT_MIN;
        int left = 0;
        int bucket = 0;
        
        for (size_t right = 0;right < fruits.size();right++) {
            bucket += fruits[right][1];
            while (left <= right && getMinSteps(fruits[left][0], fruits[right][0], startPos) > k) {
                bucket -= fruits[left][1];
                left++;
            }

            ans = max(ans, bucket);
        }

        return ans;
        

    }

    int getMinSteps(int left, int right, int startPos) {
        int goLeft = abs(startPos - left) + (right - left);
        int goRight = abs(startPos - right) + (right - left);

        return min(goLeft, goRight);
    }
};


int main() {
    vector<vector<int>> fruits = {{2, 8}, {6, 3}, {8, 6}};
    int startPos = 5;
    int k = 4;
    Solution s;
    cout << s.maxTotalFruits(fruits, startPos, k);
    return 0;
}