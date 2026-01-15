#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> singleNumber(vector<int>& nums) 
    {
        // Pass 1 : 
        // Get the XOR of the two numbers we need to find
        int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        cout << diff << "\n";
        // Get its last set bit
        diff &= -diff;

        cout << diff << " \n";

        // Pass 2 :
        vector<int> rets = {0, 0}; // this vector stores the two numbers we will return
        for (int num : nums)
        {
            if ((num & diff) == 0) // the bit is not set
            {
                cout << "BIT: " <<  num << endl;
                rets[0] ^= num;

                cout << "rets[0]: " << rets[0] << endl;
            }
            else // the bit is set
            {
                cout << "BIT: " <<  num << endl;

                rets[1] ^= num;
                cout << "rets[1]: " << rets[1] << endl;

            }
        }
        return rets;
    }
};

int main() {
    Solution st;
    vector<int> nums = {1, 2, 1, 3, 2, 5};
    for (auto i : st.singleNumber(nums)) {
        cout << i << " ";
    }

    return EXIT_SUCCESS;
}