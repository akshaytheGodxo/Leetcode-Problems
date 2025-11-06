#include <bits/stdc++.h>
using namespace std;
int static matrix[501][501];

int solve(vector<int> nums1, vector<int> nums2, int n, int m) {
    if(n == 0 || m == 0) return 0;

    if (matrix[n][m] != -1) return matrix[n][m];

    if (nums1[n-1] == nums2[m-1]) return matrix[n][m] = solve(nums1, nums2, n-1, m-1);

    else {
        return matrix[n][m] = max(solve(nums1, nums2, n-1, m), solve(nums1, nums2, n, m-1));
    }

}

int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
    int ans=solve(nums1,nums2, nums1.size(), nums2.size());
    memset(matrix, -1, sizeof(memset));
    return ans;
}
int main() {
    vector<int> nums1 = {};
    vector<int> nums2 = {};
    cout << maxUncrossedLines(nums1, nums2);
    return 0;
}