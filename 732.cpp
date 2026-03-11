#include <bits/stdc++.h>
using namespace std;
class MyCalendarThree {
public:
    vector<pair<int, int>> nums;
    vector<pair<int, int>> overlapped;
    map<int, int> time;
    MyCalendarThree() {
        this->nums = nums;
        this->overlapped = overlapped;
        this->time = time;
    }
    
    int book(int start, int end) {
        time[start]++;
        time[end]--;
        int o = 0, k = 0;
        for(auto i : time) {
            k = max(k, o += i.second);
        }
        return k;
    }
};
