#include <bits/stdc++.h>

using namespace std;

// a, b, x
// Output multiple of x which is closest to a^b

long long binpow(int a, int n)
{
    long long ans = 1;
    long long pow = a;

    while (n)
    {
        if (n & 1)
            ans *= pow;
        pow *= pow;
        n >>= 1;
    }

    return ans;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int a, b, x;
        cin >> a >> b >> x;

        if (a == 1)
        {
            if (x - 1 > 1)
                cout << 0 << endl;
            else
                cout << x << endl;
            continue;
        }
        if (b < 0)
        {
            cout << 0 << endl;
            continue;
        }

        long long expo = binpow(a, b);

        long long fact = expo % x;

        if (fact <= x / 2)
            cout << expo - fact << endl;
        else
            cout << expo - fact + x << endl;
    }

    return 0;
}