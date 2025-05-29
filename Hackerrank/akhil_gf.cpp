#include <bits/stdc++.h>

typedef long long LL;

using namespace std;

long long mod_mul(long long x, long long y, long long n)
{
    if (!x)
        return 0;
    return (((x & 1) * y) % n + (mod_mul(x >> 1, y, n) << 1) % n) % n;
}

long long ModExp(long long b, long long n)
{
    long long c = 1, d = 10;
    while (b)
    {
        if (b & 1)
            c = mod_mul(c, d, n);
        d = mod_mul(d, d, n);
        b >>= 1;
    }
    return c;
}

LL binmodpow(LL a, LL n, LL m)
{
    LL ans = 1;
    LL pow = a;
    while (n)
    {
        if (n & 1)
            ans = (ans * pow) % m;
        pow = (pow * pow) % m;
        n >>= 1;
    }

    return ans % m;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        LL n, m;
        cin >> n >> m;

        LL t2 = 9 * m;
        LL t1 = ModExp(n, t2) - 1;

        LL ans = t1 / 9;
        if (ans < 0)
            cout << ans + m << endl;
        else
            cout << ans << endl;
    }

    return 0;
}