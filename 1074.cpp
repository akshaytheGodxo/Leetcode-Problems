#include <bits/stdc++.h>
using namespace std;

void calc2dPrefixSum(vector<vector<int>> &matrix, int x1, int x2, int y1, int y2)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> prefix(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            prefix[i][j] = prefix[i][j - 1] + matrix[i - 1][j - 1];
        }
    }

    for (int j = 1; j <= m; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            prefix[i][j] += prefix[i - 1][j];
        }
    }

    for (auto i : prefix)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target) {
    int n = matrix.size(), m = matrix[0].size();
    for (int i=0;i<n;i++) {
        for (int j=1;j<m;j++) {
            matrix[i][j] += matrix[i][j-1];
        }
    }

    unordered_map<int, int> pref;
    int res = 0;
    for (int i=0;i<n;i++) {
        for (int j = 0;j<n;j++) {
            pref[0] = 1;
            int curr = 0;

            for (int k=0;k<m;k++) {
                curr = matrix[k][j] - (i > 0 ? matrix[k][i-1] : 0);
                auto it = pref.find(cur - target);
                if (it != pref.end()) {
                    res += pref[cur - target];
                }
                pref[cur]++;
            }
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    calc2dPrefixSum(matrix, 0, 0, 0, 0);
    return 0;
}
