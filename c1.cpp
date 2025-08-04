#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int shrt = landStartTime[0];
        int shrtE = landDuration[0];
        char place = 'l';
        for (int i = 0;i < landStartTime.size();i++) {
            
            if (landStartTime[i] < shrt) {

                shrt =  landStartTime[i];
                shrtE = landDuration[i];
                place = 'l';
            }
        }
        for (int i = 0;i < waterStartTime.size();i++) {
            if (shrt > waterStartTime[i]) {
                shrt = waterStartTime[i];
                shrtE = waterDuration[i];
                place = 'w';
            
            }

        }
        int ans = shrt + shrtE;
        cout << ans;
        cout << place << "\n";
        if (place == 'w') {
            // starting on land;
            cout << "on land\n";
            int k = ans + landDuration[0];
            for (int i = 1;i < landStartTime.size();i++) {
                int j = ans;
                if (j >= landStartTime[i]) {

                j +=  landDuration[i];

                k = min(j, k);
                }
            }

            ans = k;
        } else {
            cout << "on water\n";

            int k = ans +  waterStartTime[0];
            for (int i = 1;i < waterStartTime.size();i++) {
                int j = ans;
                
                if (j >= waterStartTime[i])
                {j += waterDuration[i];
                k = min(j, k);   }         
            }

            ans = k;
        }

        return ans;

    }
};

int main() {
    vector<int> lT = {2, 8};
    vector<int> ld = {4, 1};
    vector<int> wT = {6};
    vector<int> wD = {3};

    Solution s;
    cout<< s.earliestFinishTime(lT, ld, wT, wD);
    return 0;
}