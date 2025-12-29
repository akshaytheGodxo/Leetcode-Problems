#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        string st;
        cin >> st;

        int count = 0;
        int prev = -1;

        for (int i = 0; i < n; i++)
        {
            if (st[i] == '1')
            {
                prev = i;
            }
            else
            {
                if (prev == -1 || (prev + k) < i)
                    count++;
            }
        }

        cout << count << "\n";
    }

    return 0;
}
