#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int calcSum(vector<int>& nums, int s) {
    
}

int subarrayDivByK(vector<int>& nums, int k) {
    unordered_map<int, int> umap;
    // sum and frequency of the prefix sum

    int sum = 0, freq = 0;
    for (int i = 0;i < nums.size();i++) {

    }

}

int main() {
    vector<int> nums = {4,5,0,-2,-3,1};
    int k = 5;

    int ans = subarrayDivByK(nums, k);
    cout << ans << endl;
    return 0;
}