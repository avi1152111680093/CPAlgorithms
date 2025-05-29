#include <bits/stdc++.h>

using namespace std;

long long binpowmod(int a, int n, int mod)
{
    long long ans = 1;
    long long pow = a;

    while (n)
    {
        if (n & 1)
            ans = (ans * pow) % mod;
        pow = (pow * pow) % mod;
        n >>= 1;
    }

    return ans;
}

int gcd(int a, int b)
{
    while (b)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}

// Here p is prime number
pair<int, int> generator(int p)
{
    // phi(p) = p-1
    // Factorize p-1
    vector<int> factors;
    int phi = p - 1;
    int n = phi;

    int total = 1;
    for (int i = 2; i < phi; i++)
        if (gcd(i, phi) == 1)
            total++;

    // Getting all prime factors of phi
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0)
        {
            factors.push_back(i);
            while (n % i == 0)
                n /= i;
        }
    if (n > 1)
        factors.push_back(n);

    for (int res = 2; res <= p; ++res)
    {
        bool ok = true;
        // Calculate res^phi/(factors[i]) % n
        for (int factor : factors)
        {
            long long pow = binpowmod(res, phi / factor, n);
            if (pow % p == 1)
            {
                ok = false;
                break;
            }
        }
        if (ok)
            return {res, total};
    }
    return {-1, -1};
}

int main()
{
    pair<int, int> ans = generator(13);
    cout << ans.first << ' ' << ans.second << endl;

    return 0;
}