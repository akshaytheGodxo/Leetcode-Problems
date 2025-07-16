#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        if (n == 0) return eventTime;
        vector<int> gaps(n+1, 0);
        gaps[0] = startTime[0];
        for (int i = 1;i < n;i++) {
            gaps[i] = startTime[i] - endTime[i-1];

        }
        gaps[n] = eventTime - endTime[n-1];

        vector<int> rightGaps(n+1, 0);


        for (int i = n - 1;i >= 0;i--) {
            rightGaps[i] = max(rightGaps[i+1], gaps[i+1]);
        }

        int maxFree = 0, largestLeft = 0;
        for (int i = 1;i <= n;i++) {
            int duration = endTime[i-1] - startTime[i-1];
            bool canFitLeft = largestLeft >= duration;
            bool canFitRight = rightGaps[i] >= duration;

            if (canFitLeft || canFitRight) {
                int merged = gaps[i-1] + gaps[i] + duration;
                maxFree = max(maxFree, merged);
            }

            maxFree = max(maxFree, gaps[i-1] + gaps[i]);
            largestLeft = max(largestLeft, gaps[i - 1]);
        }

        return maxFree;

    }
};


int main() {
    vector<int> startTime = {1,3};
    vector<int> endTime = {2,5};
    int eventTime = 5;

    Solution s;
    cout << s.maxFreeTime(eventTime, startTime, endTime);
    
    return 0;
}