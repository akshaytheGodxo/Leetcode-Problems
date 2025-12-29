#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<vector<int>> buildGraph(vector<vector<int>>& adj, int numCourses) {
        vector<vector<int>> graph(numCourses);
        for (auto& p : adj) {
            int a = p[0];
            int b = p[1];
            graph[b].push_back(a);
        }
        return graph;
    }

public:
    vector<int> canFinish(int numCourses, vector<vector<int>>& adj) {
        int n = numCourses;
        vector<int> ans;
        vector<vector<int>> newGraph = buildGraph(adj, n);
        vector<int> indegree(newGraph.size(), 0);
        // getting nodes indegree
        for (int i = 0; i < newGraph.size(); i++) {
            for (int& x : newGraph[i]) {
                indegree[x] += 1;
            }
        }

        // printing the indegrees
        // for (auto i : indegree) cout << i << " ";
        // cout << endl;

        // getting the start points
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // bfs loop
        while (!q.empty()) {
            int f = q.front();
            q.pop();
            ans.push_back(f);
            for (int x : newGraph[f]) {
                indegree[x]--;
                if (indegree[x] == 0) {
                    q.push(x);
                }
            }
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> graph = {
        {0, 1}, {0, 2}, {2, 3}, {3, 4}
    };

    Solution s;
    // vector<int> ans = s.topologicalSort(graph);
    // cout << ans.size();
    
    vector<int> ans = s.canFinish(graph.size(), graph);
    for (auto i : ans) {
        cout << i << " ";
    }

    return EXIT_SUCCESS;
}