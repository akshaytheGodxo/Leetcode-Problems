#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        umap[0] = -1;
        int sum = 0;
        bool ans = false;
        for (int i = 0;i < nums.size();i++) {
            sum += nums[i];
            int rem = sum % k;
            if (umap.find(rem) != umap.end()) {
                int diff = i - umap[rem];
                if (diff >= 2) {
                    return true;
                }
            }
            else 
                umap[rem] = i;
        }
        return false;
}

int main() {
    vector<int> v = {23, 2, 6, 4 , 7};
    int k = 13;

    bool ans = checkSubarraySum(v, k);
    cout << ans << endl;
    return 0;
}