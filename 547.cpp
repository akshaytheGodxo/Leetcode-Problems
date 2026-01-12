#include <bits/stdc++.h>
using namespace std;


class Solution {
private:
    void dfs(int start, vector<int> lst[], vector<int> &visited) {
        visited[start] = 1;

        for (auto it : lst[start]) {
            if (!visited[it]) {
                dfs(it, lst, visited);
            }
        }
    }

public:


    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();
        vector<int> lst[n];
        for (int i = 0;i<n;i++) {
            for (int j = 0;j < n;j++) {
                if (isConnected[i][j] == 1 && i != j) {
                
                    lst[i].push_back(j);
                    lst[j].push_back(i);
                }
            }
        }


        vector<int> visited(n, 0);
        int cnt = 0;
        for (int i = 0;i < n;i++) {
            if (!visited[i]) {
                cnt++;
                dfs(i, lst, visited);
            }
        }   

        return cnt;
    }
};


int main() {
    Solution s;
    vector<vector<int>> con = {
        {1,1,0},
        {1,1,0},
        {0,0,1}
    };
    cout << s.findCircleNum(con);

}