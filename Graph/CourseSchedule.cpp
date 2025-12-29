#include <bits/stdc++.h>
using namespace std;

class Solution {
private: 
    void bfs(vector<vector<int>> &graph, vector<int> visited, int node) {
        queue<int> q;
        q.push(node);
        visited[node] = 1;
        while (!q.empty()) {
            int fr = q.front();
            q.pop();
            for (int nbr : graph[fr]) {
                if (!visited[nbr]) {
                    visited[nbr] = 1;
                    q.push(nbr);
                } else {
                    visited[nbr] = 0;
                    q.push(nbr);
                }
            }
        }
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> visited(numCourses);
        for (int i=0;i<prerequisites.size();i++) {
            int a=prerequisites[i][0], b=prerequisites[i][1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        bfs(graph, visited, 0);
        return visited[numCourses-1];
    }
};

int main() {
    Solution s;
    int n=2;
    vector<vector<int>> edges = {{0,1}, {1,0}};
    int sourc=0, destination=2;
    // cout << s.validPath(n, edges, sourc, destination);
    cout << s.canFinish(n, edges);
    return 0;
}