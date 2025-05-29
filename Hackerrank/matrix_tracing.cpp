#include <bits/stdc++.h>

#define MAX 2000000
#define MOD 1000000007

using namespace std;

long long int inverse_factorials[MAX];
long long int factorials[MAX];

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

    for (long long int i = 2; i <= MAX; i++)
    {
        factorials[i] = (factorials[i - 1] * i) % MOD;
        inverse_factorials[i] = binpow(factorials[i], MOD - 2);
    }
}

long long int solve(int m, int n)
{
    long long int ans = factorials[m + n - 2];
    ans = (ans * inverse_factorials[m - 1]) % MOD;
    ans = (ans * inverse_factorials[n - 1]) % MOD;

    return ans;
}

int main()
{
    initialize();

    cout << factorials[0] << endl;

    int t;
    cin >> t;

    while (t--)
    {
        int m, n;
        cin >> m >> n;

        cout << solve(m, n) << endl;
    }

    return 0;
}