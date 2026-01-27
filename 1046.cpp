#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        int n=stones.size();
        priority_queue<int> pq;
        for (int i=0;i<n;i++) {
            pq.push(stones[i]);
        }

        int total = 0;
        while (pq.size() > 1) {
            int first = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();

            if (first != second) 
                pq.push(first - second);

            
        }

        return pq.empty() ? 0 : pq.top();
    }
};
int main()
{
    Solution solution;
    vector<int> stones = {2,7,4,1,8,1};
    cout << solution.lastStoneWeight(stones);
    return 0;
}