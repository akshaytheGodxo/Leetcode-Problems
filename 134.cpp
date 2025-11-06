#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int total_gas = 0, total_cost = 0;
        int curr_gas = 0, starting_point = 0;
        for (uint8_t i=0;i<n;i++) {
            total_gas += gas[i];
            total_cost += cost[i];

            curr_gas +=gas[i] - cost[i];
            if (curr_gas < 0) {
                starting_point = i+1;
                curr_gas = 0;
            }
        }

        return (total_gas < total_cost) ? -1 : starting_point;
    }
};


int main() {
    Solution s;
    vector<int> gas =  {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};

    cout << s.canCompleteCircuit(gas, cost);
    return EXIT_SUCCESS;
}