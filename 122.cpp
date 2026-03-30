#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi = 0;
        int low = prices[0];
        int res = 0;
        for (int i=0;i<prices.size();i++) {
            
            if (prices[i] > low) {
                maxi += prices[i] - low;
            }
            low = prices[i];
        }
        return maxi == INT_MIN ? 0 : maxi;
    }
};
int main() {
    Solution s;
    vector<int> profit =  {7,1,5,3,6,4};

    cout << s.maxProfit(profit);
    return EXIT_SUCCESS;
}