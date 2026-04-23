#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    using p = pair<int, int>;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<p>> adj(n + 1);
        for(const auto t : times) {
            int u = t[0], v = t[1], w = t[2];
            adj[u].push_back({v, w});
        }

        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        priority_queue<p, vector<p>, greater<p>> pq;
        pq.push({0, k});

        while(!pq.empty()) {
            const auto [currDist, node] = pq.top(); 
            pq.pop();

            if(currDist > dist[node]) continue;

            for(const auto [adjNode, weight] : adj[node]) {
                int newDist = currDist + weight;

                if(newDist < dist[adjNode]) {
                    dist[adjNode] = newDist;
                    pq.push({newDist, adjNode});
                }
            }
        }

        int time = 0;
        for(int i = 1; i <= n; i++) {
            if(dist[i] == INT_MAX) return -1;
            time = max(time, dist[i]);
        }

        return time;
    }
};
int main() {
    Solution solution;
    vector<vector<int>> times = {{2,1,1},{2,3,1},{3,4,1}};
    cout << solution.networkDelayTime(times, 4, 2);
    return 0;
}