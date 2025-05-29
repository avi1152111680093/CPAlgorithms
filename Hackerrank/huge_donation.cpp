#include <bits/stdc++.h>

typedef long long LL;

using namespace std;

LL solve(LL x)
{
    LL low = 0;
    LL high = 1000000;

    while (low <= high)
    {
        LL mid = (low + high) / 2;
        LL tot = mid * (mid + 1) * (2 * mid + 1) / 6;
        LL next_tot = (mid + 1) * (mid + 2) * (2 * mid + 3) / 6;
        LL prev_tot = mid * (mid - 1) * (2 * mid - 1) / 6;
        if (tot <= x && next_tot > x)
        {
            return mid;
        }
        else if (tot > x && prev_tot <= x)
        {
            return mid - 1;
        }
        else if (tot < x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        LL n;
        cin >> n;

        cout << solve(n) << endl;
    }

    // LL x = 1000000;
    // LL n = x * (x + 1) * (2 * x + 1);

    // cout << n << endl;

    // 13*6 = 78

    // cout << solve(13) << endl;

    return 0;
}