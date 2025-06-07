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

long long mod_mult(long long a, long long b, long long c)
{
    a %= c;
    long long ret = 0;

    while (b)
    {
        if (b & 1)
        {
            ret += a;
            if (ret >= c)
                ret -= c;
        }

        a <<= 1;
        if (a >= c)
            a -= c;
        b >>= 1;
    }

    return ret;
}

#define MAXN 200000
long long arr[MAXN];

bool check(int l, int r, int k)
{
    if (l > r)
        return k <= 1;

    int lg = 0;
    long long aux = 1;

    while (aux < k)
    {
        if (aux <= LLONG_MAX / arr[l])
            aux *= arr[l];
        else
            aux = LLONG_MAX;
        ++lg;
    }

    return check(l + 1, r, lg);
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int t;
    cin >> t;
    while (t--)
    {
        LL i, j, x;
        cin >> i >> j >> x;
        i--;
        j--;

        bool ok = true;

        if (arr[i] != 0)
        {
            if (j > i && arr[i + 1] == 0)
            {
                if (x > 1)
                    ok = false;
            }
            else
            {
                int k = 0;
                LL temp = 1;
                while (k <= 53 && temp % x != 0)
                {
                    temp = mod_mult(temp, arr[i], x);
                    k++;
                }
                if (k == 54)
                    ok = false;
                else
                {
                    int len = 0;

                    for (int m = i + 1; m <= j && arr[m] > 1; ++m)
                        ++len;

                    if (i + len + 1 <= j && arr[i + len + 1] == 0)
                        --len;
                    if (len < 4 && !check(i + 1, i + len, k))
                        ok = false;
                }
            }
        }

        printf("%s\n", ok ? "Yes" : "No");
    }

    return 0;
}