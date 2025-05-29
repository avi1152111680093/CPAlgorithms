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
    int t;
    cin >> t;

    while (t--)
    {
        LL a, b, x, y;
        cin >> a >> b >> x >> y;

        if (gcd(a, b) == gcd(x, y))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}