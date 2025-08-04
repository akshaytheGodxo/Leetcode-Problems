#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        map<int, int> freq;
        map<int, int> count1;
        int n = basket1.size();
        for (int i = 0;i < n;i++) {
            freq[basket1[i]]++;
            freq[basket2[i]]++;
            count1[basket1[i]]++;
        }
        vector<long long> fts;
        long long min_val = LLONG_MAX;
        for (auto p: freq) {
            int fruit = p.first;
            int count = p.second;
            min_val = min(min_val,(long long)fruit);
            if (count % 2 != 0) return -1;
            int diff = abs(count1[fruit] - freq[fruit] / 2);

            for (int i = 0;i < diff;i++) {
                fts.push_back(fruit);
            }
        }

        sort(fts.begin(), fts.end());
        long long total_cost = 0;

        int k = fts.size() / 2;

        for (int i = 0;i < k;i++) {
            total_cost += min(fts[i], min_val * 2);
        }

        return total_cost;

    }
};

int main() {
    vector<int> b1 = {4,2,2,2};
    vector<int> b2 = {1,4,1,2};
    Solution s;
    cout << s.minCost(b1, b2);
    return 0;
}


