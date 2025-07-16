#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortArr(vector<vector<int>>& events) {
        sort(events.begin(), events.end(),[](int a[2], int b[2]) {
            return a > b;
        });
    }

    int maxValue(vector<vector<int>>& events, int k) {
              sortArr(events);
              return 0;
    }
};

int main() {
    Solution s;
    vector<vector<int>> events = {{1, 2, 4},{3, 4, 3}, {2, 3, 1}};
    int k = 2;


    cout << s.maxValue(events, k);
    
    for (auto i : events) {
        for (auto j : i) {
            cout << j << " ";
        } cout << "\n";
    }
    return 0;

}