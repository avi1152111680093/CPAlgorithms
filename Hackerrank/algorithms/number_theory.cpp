#include <bits/stdc++.h>
#define MOD 1000000007

typedef long long LL;

using namespace std;

vector<LL> primes;
bool isprime[100003];

void seive_eratho()
{
    memset(isprime, true, 100003);

    for (int i = 2; i < 100003; i++)
    {
        if (isprime[i] == false)
            continue;
        for (int j = 2; j < 100003 / i; j++)
            isprime[i * j] = false;
        if (isprime[i] == true)
            primes.push_back(i);
    }
}

LL binpow(LL a, LL n)
{
    LL ans = 1;
    LL curr = a;

    while (n)
    {
        if (n & 1)
            ans *= curr;

        curr *= curr;
        n >>= 1;
    }

    return ans;
}

LL num_of_divisors(LL n)
{
    LL ans = 1;

    for (LL p : primes)
    {
        if (n < p)
            break;

        LL e = 0;
        while (n % p == 0)
        {
            e++;
            n /= p;
        }

        ans *= (e + 1);
    }
    if (n > 1)
        return ans * 2;

    return ans;
}

LL sum_of_divisors(LL n)
{
    LL ans = 1;

    for (LL p : primes)
    {
        if (n < p)
            break;

        LL e = 0;
        while (n % p == 0)
        {
            e++;
            n /= p;
        }
        // ans *= (binpow(p, e + 1) - 1) / (p - 1);

        LL sum = 0;
        LL curr_pow = 1;
        do
        {
            sum += curr_pow;
            curr_pow *= p;
        } while (e-- > 0);

        ans *= sum;
    }

    if (n > 1)
        return ans * (n + 1);

    return ans;
}

// 2, 4
// n = 2^5 * 3^6 =

LL sumof_sumof_divisor(LL n)
{
    LL ans = 1;

    for (LL p : primes)
    {
        if (n < p)
            break;

        LL e = 0;
        while (n % p == 0)
        {
            e++;
            n /= p;
        }

        LL sum = 0;
        LL curr_pow = 1;
        do
        {
            sum += (curr_pow * (e + 1));
            curr_pow *= p;
        } while (e-- > 0);

        ans *= sum;
    }
    if (n > 1)
        return ans * (n + 2);

    return ans;
}

int main()
{
    seive_eratho();

    cout << sumof_sumof_divisor(23328) << endl;

    return 0;
}