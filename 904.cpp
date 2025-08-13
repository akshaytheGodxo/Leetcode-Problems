#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int maxFruits = INT_MIN;
        vector<int> basket = {fruits[0]};
        vector<int> uniqueFruits(2, 0);
        int cnt = 0;
        int k = 0;
        for (int i = 1;i < fruits.size();i++) {
            if (fruits[i] != basket[0]) {
                k = i;
                cnt++;
                basket.push_back(fruits[i]);
                break;
            }
            else {cnt++; basket.push_back(fruits[i]);}
        }

        uniqueFruits[0] = basket[0];
        uniqueFruits[1] = fruits[k];
        maxFruits = cnt;
        if (k+1 != fruits.size()) {
            for (int i = k + 1;i < fruits.size();i++) {
                if (fruits[i] != uniqueFruits[0] || fruits[i] != uniqueFruits[1]) {
                    cnt += fruits[i] - fruits[i - k];
                    
                } else {

                }
            }
        }

    }
};

int main() {
    Solution s;
    vector<int> fruits = {1,2,1};
    cout << s.totalFruit(fruits);
    return 0;
}