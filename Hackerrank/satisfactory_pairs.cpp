#include <bits/stdc++.h>

typedef long long LL;

using namespace std;

LL gcd(LL a, LL b, LL &x, LL &y)
{
    x = 1, y = 0;
    LL x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1)
    {
        LL q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}

bool is_valid_ans(LL a, LL b, LL c)
{
    LL x, y;
    LL g = gcd(a, b, x, y);

    if (c % g)
        return false;

    x *= (c / g);
    y *= (c / g);

    // cout << a << ' ' << b << endl;
    // cout << x << ' ' << y << endl;
    // cout << endl;
    if (x < 0 && y < 0)
        return false;
    if (x < 0)
    {
        LL i = ceil(g * abs(x) / b);
        if (i == g * abs(x) / b)
            i++;
        // cout << i << endl;
        double t = g * abs(y) / (double)a;
        // cout << t << endl;
        return i < t;
    }
    if (y < 0)
    {
        LL i = ceil(g * abs(y) / a);
        if (i == g * abs(y) / a)
            i++;
        double t = g * abs(x) / (double)b;
        return i < t;
    }

    return true;
}

int main()
{
    LL n;
    cin >> n;

    LL ans = 0;
    for (int i = 2; i <= ((n - 1) >> 1); i++)
    {
        for (int j = i + 1; j + i <= n; j++)
        {
            if (is_valid_ans(i, j, n))
            {
                // cout << i << ' ' << j << endl;
                ans++;
            }
        }
    }

    cout << ans + n - 2 << endl;

    return 0;
}