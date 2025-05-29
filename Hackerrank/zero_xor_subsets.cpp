#include <bits/stdc++.h>
#define MOD 1000000007

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

    return ans;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        LL n;
        cin >> n;

        cout << (binpowmod(2ll, binpowmod(2ll, n, MOD - 1ll), MOD) * binpowmod(binpowmod(2, n, MOD), MOD - 2ll, MOD)) % MOD << endl;
    }

    return 0;
}