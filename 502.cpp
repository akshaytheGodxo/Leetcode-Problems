// IPO 

/*
    approach
    all of this only if the project_count <= k
    a subarray called candidates -> where capital = w and values append from profit
    then we find out the max value and it's index
    then we add that amount of profit to a variable called total_capital
    then repeat this step again
    if project_count > k
    break;
    return total_capital;



    approach 2: 
    use a map
    store all the profit of a price in an array called candidate
    traverse throuh it
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
class Solution {
public:
    static bool cmp(pair<int, int>& a, pair<int, int>& b) {
        if (a.second != b.second)
            return a.second < b.second;
        return a.first < b.first;
    }
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        
        vector<pair<int, int>> projects(n);
        for (int i = 0;i < n;i++)
            projects[i] = {profits[i], capital[i]};
        
        sort(projects.begin(), projects.end(), cmp);
        int i = 0;
        priority_queue<int> PQ;

        while (k--) {
            while (i < n && projects[i].second <= w) {
                PQ.push(projects[i].first);
                i++;
            }
            if (!PQ.empty()) {
                w += PQ.top();
                PQ.pop();
            }
        }
        return w;
    }
};

int main() {
    Solution solution;
    vector<int> profits = {0,1,2,3,4,5};
    int k = 3;
    int w = 0;
    vector<int> capital = {0,1,1,1,1,1};

    solution.findMaximizedCapital(k, w, profits, capital);
    
    return 0;
}