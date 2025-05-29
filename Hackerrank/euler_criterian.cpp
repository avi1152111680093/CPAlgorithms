#include <bits/stdc++.h>

typedef long long LL;

using namespace std;

LL binpowmod(LL a, LL b, LL mod)
{
    LL ans = 1;
    LL pow = a;

    while (b)
    {
        if (b & 1)
            ans = (ans * pow) % mod;
        pow = (pow * pow) % mod;
        b >>= 1;
    }

    return ans % mod;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        LL a, b;
        cin >> a >> b;

        if (a == 0 || binpowmod(a, (b - 1) / 2, b) == 1)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}