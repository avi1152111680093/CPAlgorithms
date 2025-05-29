#include <bits/stdc++.h>

typedef long long LL;

using namespace std;

vector<vector<LL>> pascalTriangle;
int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};

LL binomial_coefficient(int n, int k)
{
    if (n < k)
        return 0;
    LL ans = 1;
    k = k < (n - k) ? k : (n - k);
    for (int i = 1; i <= k; i++, n--)
    {
        if (n % i == 0)
        {
            ans *= n / i;
        }
        else if (ans % i == 0)
        {
            ans = (ans / i) * n;
        }
        else
        {
            ans = (ans * n) / i;
        }
    }
    return ans;
}

LL remUsingLucas(int n, int k, int p)
{
    LL ans = 1;
    while (k > 0)
    {
        int tmp_n = n % p;
        int tmp_k = k % p;
        ans *= binomial_coefficient(tmp_n, tmp_k) % p;
        ans %= p;
        n /= p;
        k /= p;
    }
    return ans;
}

LL get_reminder_squarefree(int n, int k, int m)
{
    LL ans = -1;
    LL last = 1;
    int primes_length = sizeof(primes) / sizeof(int);

    if (m == 1)
        return 0;

    for (int i = 0; i < primes_length && m > 1; i++)
    {
        if (m % primes[i] != 0)
            continue;

        LL rem = remUsingLucas(n, k, primes[i]);

        if (ans == -1)
            ans = rem;
        else
        {
            for (int j = 0; j < 50; j++)
            {
                if ((ans + (last * j)) % primes[i] == rem)
                {
                    ans = (ans + (last * j));
                    break;
                }
            }
        }
        last *= primes[i];
        m /= primes[i];
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m, r;
        cin >> n >> r >> m;
        cout << get_reminder_squarefree(n, r, m) << endl;
    }

    return 0;
}