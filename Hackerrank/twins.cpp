#include <bits/stdc++.h>

typedef long long LL;

using namespace std;

vector<long long> primes;
// int n;
// vector<bool> is_prime(n+1, true);
// is_prime[0] = is_prime[1] = false;
// for (int i = 2; i * i <= n; i++) {
//     if (is_prime[i]) {
//         for (int j = i * i; j <= n; j += i)
//             is_prime[j] = false;
//     }
// }
vector<bool> sieve_erato(int n)
{
    n = 1000000000;
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= 1000000000; i++)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    for (int i = 2; i <= n; i++)
        if (is_prime[i])
            primes.push_back(i);

    return is_prime;
}

vector<int> gen_primes()
{
    vector<int> primes;

    for (int i = 2; i * i <= 1000000000; i++)
    {
        bool ok = true;
        for (int j = 2; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                ok = false;
                break;
            }
        }
        if (ok)
            primes.push_back(i);
    }

    return primes;
}

int main()
{
    int a, b;

    cin >> a >> b;

    vector<int> primes = gen_primes();

    int lst = -1;
    int ans = 0;

    for (int i = a; i <= b; i++)
    {
        bool ok = true;
        for (int prime : primes)
        {
            if (prime * prime > i)
                break;
            if (i % prime == 0)
            {
                ok = false;
                break;
            }
        }

        if (ok && i > 1)
        {
            ans += (lst == i - 2);
            lst = i;
        }
    }

    cout << ans << endl;

    // for (int i = 0; i < 100; i++)
    //     cout << primes[i] << ' ';

    return 0;
}