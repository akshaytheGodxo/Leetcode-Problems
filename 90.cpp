#include <bits/stdc++.h>
using namespace std;
// after every addition push it to the answer vector
void solve(int i, vector<vector<int>>& ans, vector<int>& nums, vector<int>& tracker, int size) {
    if (i == size) {
        ans.push_back(tracker);
        return ;
    }
    for (int i = 0;i < size;i++) {
        ans.push_back(tracker);
    }
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> ans;

}

int main() {
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> ans = subsetsWithDup(nums);

    for (auto i : ans) {
        for (auto j : i) {
            cout << j << " "; 
        }
        cout << endl;
    }
    return 0;
}