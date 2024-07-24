// Sum of square number
//  for 1000 -> 18 , 26
#include <iostream>
#include <climits>
#include <cmath>
#include <string>
using namespace std;
#define ll long long
#define ll long long
class Solution {
public:
    bool judgeSquareSum(int c) {
        ll left = 0, right = static_cast<ll>(sqrt(c));
        while(left <= right) {
            if(left * left + right * right == c) return true;
            else if(left * left + right * right > c) right--;
            else left++;
        }

        return false;
    }
};

int main() {
    Solution solution;
    int x;
    cin >> x;
    bool ans = solution.judgeSquareSum(x);
    cout << ans << endl;
    return 0;
}