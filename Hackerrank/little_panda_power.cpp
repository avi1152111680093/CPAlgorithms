#include <bits/stdc++.h>

typedef long long LL;

using namespace std;

int phi(int n)
{
    int result = n;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

LL binpowmod(int a, int b, int m)
{
    LL ans = 1;
    LL pow = a;

    while (b)
    {
        if (b & 1)
            ans = (ans * pow) % m;
        pow = (pow * pow) % m;
        b >>= 1;
    }

    return ans % m;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int a, b, x;
        cin >> a >> b >> x;

        if (b < 0)
        {
            LL temp = binpowmod(a, phi(x) - 1, x);
            cout << (binpowmod(temp, -1 * b, x) + x) % x << endl;
        }
        else
            cout << binpowmod(a, b, x) << endl;
    }

    return 0;
}