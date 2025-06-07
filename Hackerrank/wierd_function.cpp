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

// for i in range(L, R+1):
//      if (perfect_sqrt(1+8*i)) {
//           j = (sqrt(1+8*i)-1)/2;
//           ans += phi(i);
//      }

bool perfect_sq(LL n)
{
    LL temp = sqrt(double(n));
    // cout << temp << endl;
    if (temp * temp == n)
        return true;
    return false;
}

LL phi(LL n)
{
    LL result = n;
    for (LL i = 2; i * i <= n; i++)
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

int main()
{
    LL n = 1414215;
    vector<LL> phis;
    phis.resize(n + 1);
    for (LL i = 0; i <= n; i++)
        phis[i] = i;
    for (LL i = 2; i <= n; i++)
    {
        if (phis[i] == i)
        {
            for (LL j = i; j <= n; j += i)
                phis[j] -= phis[j] / i;
        }
    }

    vector<LL> temp;
    temp.resize(n + 1, 0);
    for (LL i = 1; i <= n; i++)
    {
        if (i % 2)
            temp[i] = phis[i] * phis[(i + 1) / 2];
        else
            temp[i] = phis[i / 2] * phis[(i + 1)];
    }
    for (LL i = 1; i <= n; i++)
        temp[i] += temp[i - 1];

    int t;
    cin >> t;

    while (t--)
    {
        LL L, R;
        cin >> L >> R;

        LL l, r;

        l = (sqrt(1 + 8 * L) - 1) / 2;
        r = (sqrt(1 + 8 * R) - 1) / 2;
        if ((l * (l + 1)) == 2 * L)
        {
            cout << (temp[r] - temp[l - 1]) << endl;
        }
        else
        {
            cout << (temp[r] - temp[l]) << endl;
        }
    }

    return 0;
}