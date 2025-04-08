#include <bits/stdc++.h>
using namespace std;


class Solution {
private:
	long long calc(int multiplier, int range) {
		long long ans = 0;
		for (int i = 1;i <= range;i++) {
			ans += range*multiplier;
		}

		return ans;
	}
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long ans = 0;

        for (int i = 0;i < workerTimes.size();i++) {
        	int height = 0;
        	int step = 1;
        	while (height < mountainHeight) {
        		height += step * workerTimes[i];
        		step++;
        	}

        	ans = (ans > height) ? ans : height;
        }

        return ans;
    }
};


int main(int argc, char const *argv[])
{
	int mountainHeight = 12;
	vector<int> workerTimes = {3,2,2,4};
	Solution s;
	long long ans = s.minNumberOfSeconds(mountainHeight, workerTimes);
	cout << ans << endl;
	return 0;
}