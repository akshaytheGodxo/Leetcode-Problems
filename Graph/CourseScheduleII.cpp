#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<vector<int>> buildGraph(int n, vector<vector<int>> &adj) {
        vector<vector<int>> graph(n);
        for (auto i : adj) {
            int a = i[0];
            int b = i[1];

            graph[b].push_back(a);
        }

        return graph;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> graph = buildGraph(n, prerequisites);
        vector<int> ans;
        vector<int> indegree(n, 0);
        for (int i=0;i<n;i++) {
            for (int &x : graph[i]) {
                indegree[x] += 1;
            }
        }


        queue<int> q;
        // searching for the root node;


        for (int i=0;i<n;i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int fr = q.front();
            q.pop();
            ans.push_back(fr);
            for (int nbr : graph[fr]) {
                indegree[nbr]--;
                if (indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }
        vector<int> empty;
        return ans.size() == n ? ans : empty;
    }

};