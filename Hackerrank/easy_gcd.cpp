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

LL smallestFactor(LL n)
{
    LL factor = 2;
    while (factor * factor <= n)
    {
        if (n % factor == 0)
            return factor;
        factor++;
    }

    return n;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> vec = vector<int>(n);

    for (int i = 0; i < n; i++)
        cin >> vec[i];

    LL g = vec[0];
    for (int i = 1; i < n; i++)
        g = gcd(g, vec[i]);

    LL factor = smallestFactor(g);

    cout << k - k % factor << endl;

    return 0;
}