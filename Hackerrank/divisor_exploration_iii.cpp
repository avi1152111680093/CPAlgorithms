#include <bits/stdc++.h>
#define MOD 1000000007

typedef long long LL;

using namespace std;

vector<LL> primes;
bool isprime[1299710];
LL modinvs[2002];

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
    LL curr = a;

    while (n)
    {
        if (n & 1)
            ans = (ans * curr) % MOD;

        curr = (curr * curr) % MOD;
        n >>= 1;
    }

    return ans;
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

    return x1 % MOD;
}

LL solve(LL m, LL a, LL d)
{
    LL ans = 1;
    for (int i = 0; i < m; i++)
    {
        LL p = primes[i];
        LL e = a + i + 1;
        if (d == 1)
            ans = (ans * powmod(p, e)) % MOD;
        else if (d == 2)
        {
            LL t1 = powmod(p, e + 1) - 1;
            LL t2 = (t1 * modinv(p - 1, MOD)) % MOD;

            ans = (ans * t2) % MOD;
        }
        else
        {
            LL curr_p = powmod(p, e + 1);

            LL temp_ans = curr_p - 1;
            LL comb = 1;

            for (int curr_e = 1; curr_e <= e; curr_e++)
            {
                curr_p = (curr_p * modinv(p, MOD)) % MOD;
                comb = ((((d - 3 + curr_e) * modinvs[curr_e]) % MOD) * comb) % MOD;
                temp_ans = (temp_ans + (comb * (curr_p - 1)) % MOD) % MOD;
            }
            temp_ans = (temp_ans * modinv(p - 1, MOD)) % MOD;

            ans = (ans * temp_ans) % MOD;
        }
    }

    return ans;
}

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
    modinvs[0] = 1;
    for (int i = 1; i <= 2000; i++)
        modinvs[i] = modinv(i, MOD);

    int t;
    cin >> t;

    while (t--)
    {
        LL m, a, d;
        cin >> m >> a >> d;

        cout << solve(m, a, d) << endl;
    }

    return 0;
}