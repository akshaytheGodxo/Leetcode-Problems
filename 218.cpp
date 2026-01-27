#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();

        vector<pair<int, int>> rows; 
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1) cnt++;
                else break;
            }
            rows.push_back({cnt, i});
        }

        sort(rows.begin(), rows.end()); 

        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(rows[i].second);
        }

        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<int>> mat = {
        {1,1,0,0,0},
        {1,1,1,1,0},
        {1,0,0,0,0},
        {1,1,0,0,0},
        {1,1,1,1,1}
    };

    vector<int> ans = s.kWeakestRows(mat, 3);
    for (int i : ans) cout << i << " ";
}
