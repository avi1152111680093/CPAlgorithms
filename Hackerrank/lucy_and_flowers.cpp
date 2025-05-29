#include <bits/stdc++.h>
constexpr unsigned MAX = 5001;
constexpr unsigned MOD = 1000000009;
typedef unsigned long long LL;

using namespace std;

unsigned mult(unsigned a, unsigned b, unsigned mod)
{
    unsigned long long la = a;
    unsigned long long lb = b;

    return (unsigned)((la * lb) % mod);
}

unsigned long long power(unsigned long long x,
                         int y, int p)
{
    unsigned long long res = 1; // Initialize result

    x = x % p; // Update x if it is more than or
    // equal to p

    while (y > 0)
    {

        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;

        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}

// Returns n^(-1) mod p
unsigned long long modInverse(unsigned long long n,
                              int p)
{
    return power(n, p - 2, p);
}

// Returns nCr % p using Fermat's little
// theorem.
unsigned long long nCrModPFermat(unsigned long long n,
                                 int r)
{
    // If n<r, then nCr should return 0
    if (n < r)
        return 0;
    // Base case
    if (r == 0)
        return 1;

    // Fill factorial array so that we
    // can find all factorial of r, n
    // and n-r
    unsigned long long fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % MOD;

    cout << fac[5000] << endl;

    return (fac[n] * modInverse(fac[r], MOD) % MOD * modInverse(fac[n - r], MOD) % MOD) % MOD;
}

LL C[5001][5001];
LL dp[5001];

LL catalan[5001];
LL C2[5001][5001];

void precompute()
{
    // calcule les nombres de Catalan
    // https://oeis.org/A000108
    catalan[0] = 1;
    catalan[1] = 1;
    for (unsigned i = 2; i < MAX; ++i)
    {
        unsigned c = 0;
        for (unsigned j = 1; j <= i; j++)
            c = (c + mult(catalan[j - 1], catalan[i - j], MOD)) % MOD;
        catalan[i] = c;
    }

    // Caculate value of Binomial Coefficient in bottom up manner
    // https://www.geeksforgeeks.org/dynamic-programming-set-9-binomial-coefficient/
    memset(C2, 0, sizeof(C2));
    for (unsigned i = 0; i < MAX; i++)
    {
        for (unsigned j = 0; j <= i; j++)
        {
            // Base Cases
            if (j == 0 || j == i)
                C2[i][j] = 1;

            // Calculate value using previosly stored values
            else
                C2[i][j] = (C2[i - 1][j - 1] + C2[i - 1][j]) % MOD;
        }
    }
}

int main()
{
    for (LL i = 0; i < 5001; i++)
    {
        for (LL j = 0; j <= i; j++)
        {
            // Base Cases
            if (j == 0 || j == i)
                C[i][j] = 1;

            // Calculate value using previosly stored values
            else
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
        }
    }

    precompute();

    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= 5000; i++)
    {
        LL t = 0;
        for (int k = 0; k <= i - 1; k++)
            t = (t + (dp[k] * dp[i - 1 - k]) % MOD) % MOD;
        dp[i] = t;
    }

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        LL ans = 0;
        for (LL i = 1; i <= n; i++)
            ans = (ans + mult(dp[i], C[n][i], MOD)) % MOD;

        cout << ans << endl;
    }

    return 0;
}