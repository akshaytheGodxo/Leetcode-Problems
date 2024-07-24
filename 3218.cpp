#include <iostream>
#include <vector>
#include <algorithm>
int minimumCost(int m, int n, std::vector<int>& horizontalCut, std::vector<int>& verticalCut) {
    int minCost = 0;

    for (int i = 0;i < n-1;i++) {
        minCost += horizontalCut[i];
    }
    for (int j = 0;j < m-1;j++) {
        minCost += verticalCut[j]*(n);
    }
    return minCost;
 
}   

int main() {
    std::vector<int> horizontalCut = {7};
    std::vector<int> verticalCut = {4};
    int m = 2;
    int n = 2;

    int ans = minimumCost(m, n, horizontalCut, verticalCut);
    std::cout << ans << "\n";
    return 0;

}