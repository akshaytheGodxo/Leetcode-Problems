#include <bits/stdc++.h>
using namespace std;


class MyCalendarTwo {
public:
    vector<pair<int, int>> nums;
    vector<pair<int, int>> overlapped;
    MyCalendarTwo() {
        this->nums = nums;
        this->overlapped = overlapped;
    }
    
    bool book(int start, int end) {
        for (auto i : overlapped) {
            if (!(end <= i.first || start >= i.second)) {
                return false;
            }
        }

        for (auto i : nums) {
            if (end > i.first && i.second > start) {
                overlapped.push_back({max(start, i.first), min(end, i.second)});
            }

        }
        nums.push_back({start, end});

        return true;
    }
};
