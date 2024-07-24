#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end()); // for binary search purposes
        int n = position.size();
        int max_distance = position[n-1] - position[0];
        
        for (int i = 0;i < m;i++) {

        }


    }
};
int main() {
    vector<int> position = {1,2,3,4,7};
    int m = 3;
    Solution sol;
    int ans = sol.maxDistance(position, m);
    cout << ans << endl;
}