#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void inverse(string &x)
    {   

        for (char &bit : x)
        {
            if (bit == '0')
            {
                bit = '1';
            }
            else if (bit == '1')
            {
                bit = '0';
            }
        }
    }
    char findKthBit(int n, int k)
    {
        string main = "0";
        for (int i = 1; i <= n; i++)
        {   
            string k = main;
            inverse(k);
            string n = main + "1";
            reverse(k.begin(), k.end());
            n += k;
            main = n;
        }

        return main[k-1];
    }
};

int main()
{
    Solution s;
    int n, k;
    cin >> n >> k;
    cout << s.findKthBit(n, k);
    return 0;
}