// Most profit assigning work

// per worker ke liye hame maximum profit dekhna hai uski ability ke hissab se

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define sort(a) sort(begin(a), end(a))
#define opt() ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        opt();
        int res = 0, j = 0, best = 0;
        vector<pair<int, int>> temp;
        for(int i = 0; i < worker.size(); ++i) {
            temp.push_back({difficulty[i], profit[i]});
        }

        sort(temp); sort(worker);
        for(int work : worker) {
            while(work >= temp[j].first && j < worker.size()) {
                best = max(best, temp[j++].second);
            }
            
            res += best;
        }

        return res;
    }
};
int main() {
    vector<int> difficulty = {2,4,6,8,10};
    vector<int> profit = {10,20,30,40,50};
    vector<int> worker = {4,5,6,7};

    Solution sol;
    cout << sol.maxProfitAssignment(difficulty, profit, worker);
    return 0;

}