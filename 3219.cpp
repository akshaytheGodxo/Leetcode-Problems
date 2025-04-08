#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

/*
    calculate the total cost from each row and columns
*/

class Solution
{

public:
    long long minimumCost(int m, int n, vector<int> &horizontalCut, vector<int> &verticalCut) {
        int rowcost = 0;
        int colcost = 0;
        for (int i = 0;i < horizontalCut.size();i++) {
            rowcost += horizontalCut[i];
        }
        for (int j = 0;j < verticalCut.size();j++) {
            colcost += verticalCut[j];
        }

        ll ans = rowcost * m-1 + colcost * n-1;
    }
};


// maybe we can target on focusing on one single elment only into making it 1*1 cell or maybe look forward to make the whole area into 1 unit 
/*
    or maybe we can solve for each cake
    let's say cake has area of 6
    we cut it
    it got divided
    we solve the upper part 
    we cut it
    it got divided again
    we solve the upper left part
    it has area of one so we return the price
    we go to upper right cake
    it has area of one so we return the prive
    so now upper part has a total cost price of upper part = > upper left + upper right 



*/
int main()
{

    Solution sol;

    vector<int> horizontalCut = {1, 3};
    vector<int> verticalCut = {5};
    int m = 3;
    int n = 2;

    long long ans = sol.minimumCost(m, n, horizontalCut, verticalCut);
    cout << ans << endl;
    return 0;
}