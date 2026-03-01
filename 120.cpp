#include <bits/stdc++.h>

using namespace std;

int minimumTotal(vector<vector<int>> &triangle)
{
    int ans = 0, n = triangle.size();

    vector<vector<int>> mainPath(n);

    mainPath[0] = triangle[0];
    for (auto i : mainPath)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    for (int i = 1; i < n; i++)
    {
        vector<int> row;
        for (int j = 0; j < triangle[i].size(); j++)
        {
            if (j == 0)
            {
                int value = mainPath[i - 1][0] + triangle[i][j];
                row.push_back(value);
            }
            else if (j == triangle[i].size() - 1)
            {
                int value = mainPath[i - 1][triangle[i - 1].size() - 1] + triangle[i][j];
                row.push_back(value);
            }
            else
            {
                int value = min(mainPath[i - 1][j], mainPath[i - 1][j - 1]) + triangle[i][j];
                row.push_back(value);
            }
        }
        mainPath[i] = row;
    }

    for (auto i : mainPath)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    int k = mainPath.size();
    ans = *min_element(mainPath[k - 1].begin(), mainPath[k - 1].end());
    return ans;
}

int main()
{
    vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};

    cout << minimumTotal(triangle);

    return 0;
}