#include <bits/stdc++.h>

typedef long long LL;

using namespace std;

pair<LL, LL> bin_expo_complex(LL a, LL b, LL k, LL m)
{
    LL pa = a;
    LL pb = b;
    LL x1 = 1;
    LL x2 = 0;

    while (k)
    {
        if (k & 1)
        {
            LL temp_x1 = (x1 * pa) % m - (x2 * pb) % m;
            LL temp_X2 = (x1 * pb) % m + (x2 * pa) % m;
            x1 = temp_x1 % m;
            x2 = temp_X2 % m;
        }
        LL temp_pa = (pa * pa) % m - (pb * pb) % m;
        LL temp_pb = (2 * pa * pb) % m;
        pa = temp_pa % m;
        pb = temp_pb % m;

        k >>= 1;
    }

    return {(x1 + m) % m, (x2 + m) % m};
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        LL a, b, k, m;

        cin >> a >> b >> k >> m;

        auto ans = bin_expo_complex(a, b, k, m);

        cout << ans.first << ' ' << ans.second << endl;
    }

    return 0;
}