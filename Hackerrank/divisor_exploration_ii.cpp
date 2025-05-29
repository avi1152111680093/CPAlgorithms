#include <bits/stdc++.h>

#define MOD 1000000007

typedef unsigned long long LL;

using namespace std;

LL modmul(LL a, LL b, LL mod)
{
    return (__int128)a * b % mod;
}

// Extended Euclidean Algorithm
LL modinv(LL a, LL m)
{
    LL m0 = m, x0 = 0, x1 = 1;
    while (a > 1)
    {
        LL q = a / m;
        LL t = m;

        m = a % m, a = t;
        t = x0;

        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0)
        x1 += m0;

    return x1;
}

LL binpowmod(LL a, LL b, LL mod)
{
    LL ans = 1;
    LL pow = a;

    while (b)
    {
        if (b & 1)
            ans = (ans * pow) % mod;
        pow = (pow * pow) % mod;
        b >>= 1;
    }

    return ans % mod;
}

LL gcd(LL a, LL b)
{
    while (b)
    {
        a %= b;
        swap(a, b);
    }

    return a;
}

LL powmod(LL a, LL n)
{
    LL ans = 1;
    LL pow = a;
    while (n)
    {
        if (n & 1)
            ans *= pow;
        pow *= pow;
        n >>= 1;
    }

    return ans;
}

LL sum_of_divisors(LL n)
{
    LL ans = 1;

    for (LL i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            LL e = 0;
            while (n % i == 0)
            {
                e++;
                n /= i;
            }

            ans = ans * ((powmod(i, e + 1) - 1) / (i - 1));
        }
    }

    if (n > 1)
        ans *= (1 + n);

    return ans;
}

LL extended_euclidean(LL a, LL b, LL &x, LL &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    LL x1, y1;
    LL gcd = extended_euclidean(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}

unsigned long long F_num(unsigned long long p, unsigned long long a)
{
    unsigned long pow_val = binpowmod(p, a + 2, MOD);

    unsigned long term = (p + ((p - 1) * (a + 1)) % MOD) % MOD;
    unsigned long res = (pow_val - term + MOD) % MOD;
    return res;
}

unsigned long long F_den(unsigned long long p)
{
    return ((p - 1) * (p - 1)) % MOD;
}

vector<LL> primes;
bool isprime[1299710];

int main()
{
    memset(isprime, true, 1299710);

    for (int i = 2; i < 1299710; i++)
    {
        if (isprime[i] == false)
            continue;
        for (int j = 2; j <= 1299710 / i; j++)
            isprime[i * j] = false;
        if (isprime[i] == true)
            primes.push_back(i);
    }
    int t;
    cin >> t;

    while (t--)
    {
        LL n, a;
        cin >> n >> a;

        unsigned long long numerator = 1, denominator = 1;
        for (int i = 0; i < n; i++)
        {
            LL p = primes[i];
            LL e = a + i + 1;

            numerator = (numerator * F_num(p, e)) % MOD;
            denominator = (denominator * F_den(p)) % MOD;
        }
        unsigned long long r = (numerator * modinv(denominator, MOD)) % MOD;
        cout << r << '\n';
    }

    return 0;
}