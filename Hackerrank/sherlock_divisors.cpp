#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

long long int factorials[2003];
long long int inverse_factorials[2003];

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

    for (int i = 2; i <= 2001; i++)
    {
        factorials[i] = (factorials[i - 1] * i) % MOD;
        inverse_factorials[i] = binpow(factorials[i], MOD - 2);
    }
}

int solve(int n, int m)
{
    long long int ans = factorials[n + m - 1];
    ans = (ans * inverse_factorials[m]) % MOD;
    ans = (ans * inverse_factorials[n - 1]) % MOD;

    return ans;
}

int main()
{
    initialize();
    cout << factorials[3] << endl;
    cout << inverse_factorials[3] << endl;
    cout << solve(4, 1) << endl;

    return 0;
}