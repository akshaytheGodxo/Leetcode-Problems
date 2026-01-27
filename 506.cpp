#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> findRelativeRanks(vector<int> &score)
    {
        int n=score.size();
        priority_queue<pair<int, int>> heap;
        for (int i=0;i<n;i++){ 
            heap.push({score[i], i});
        }
        vector<string> rank(n);
        int place = 1;
        while (!heap.empty()) {
            cout << heap.top().first << " ";
            int idx = heap.top().second;
            heap.pop();
            if (place == 1) {
                rank[idx] = "Gold Medal";
            } else if (place == 2) {
                rank[idx] = "Silver Medal";
            } else if (place == 3) {
                rank[idx] = "Bronze Medal";
            } else {
                rank[idx] = to_string(place);
            }

            place++;
        }
        cout << endl;
        return rank;
    }
};

int main()
{


    Solution st;
    vector<int> score = {5,4,3,2,1};
    vector<string> ans = st.findRelativeRanks(score);
    for (auto i:ans) cout << i << " ";
}