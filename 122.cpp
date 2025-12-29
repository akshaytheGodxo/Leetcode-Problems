#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_prof = 0;
        int curr_stock = prices[0];
        int n = prices.size();
        for (uint64_t i=1;i<n;i++) {
            cout << curr_stock << "\n";
            if (curr_stock<prices[i]) {
                max_prof += prices[i] - curr_stock;
            }
            curr_stock = prices[i];
        }
        return max_prof;
    }
};

int main() {
    Solution s;
    vector<int> profit =  {7,1,5,3,6,4};

    cout << s.maxProfit(profit);
    return EXIT_SUCCESS;
}