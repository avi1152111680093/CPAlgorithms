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
    }

    return 0;
}