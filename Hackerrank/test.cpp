#include <bits/stdc++.h>

#define MAX 2000000
#define MOD 1000000007

using namespace std;

typedef long long LL;

long long int inverse_factorials[MAX];
long long int factorials[MAX];

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

long long int binpow(long long int a, long long int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

void initialize()
{
    factorials[0] = 1;
    factorials[1] = 1;
    inverse_factorials[0] = 1;
    inverse_factorials[1] = 1;

    for (long long int i = 2; i < MAX; i++)
    {
        factorials[i] = (factorials[i - 1] * i) % MOD;
        inverse_factorials[i] = binpow(factorials[i], MOD - 2);
    }
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

    // for (LL prime : primes)
    // {
    //     if (modinv(prime - 1, MOD) * (prime - 1) % MOD != 1)
    //         cout << prime << endl;
    //     // cout << modinv(prime - 1, MOD) << endl;
    // }
    // for (int i = 1; i < 2002; i++)
    // {
    //     if (modinv(i, MOD) * i % MOD != 1)
    //         cout << i << endl;
    //     // cout << modinv(i, MOD) << endl;
    // }
    cout << (binpow(23, 100) * modinv(23, MOD)) % MOD << endl;
    cout << binpow(23, 99) << endl;

    return 0;
}