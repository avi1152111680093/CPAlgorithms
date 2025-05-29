#include <bits/stdc++.h>

typedef long long LL;

using namespace std;

LL gcd(LL a, LL b)
{
    while (b)
    {
        a %= b;
        swap(a, b);
    }

    return a;
}

int main()
{
    LL n, t;
    cin >> n >> t;
    LL arr[n];

    for (LL i = 0; i < n; i++)
        cin >> arr[i];

    LL g = 0;
    for (LL i = 0; i < n; i++)
        g = gcd(g, arr[i]);

    while (t--)
    {
        LL k;
        cin >> k;
        LL ans = gcd(g, arr[0] + k);
        cout << ans << endl;
    }

    return 0;
}