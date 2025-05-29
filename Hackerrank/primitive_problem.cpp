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

int powmod(int a, int b, int p)
{
    int res = 1;
    while (b)
        if (b & 1)
            res = int(res * 1ll * a % p), --b;
        else
            a = int(a * 1ll * a % p), b >>= 1;
    return res;
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

vector<long long> primes;

void sieve_erato(int n)
{
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++)
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
}

vector<long long> trial_division4(long long n)
{
    vector<long long> factorization;
    for (long long d : primes)
    {
        if (d * d > n)
            break;
        while (n % d == 0)
        {
            factorization.push_back(d);
            n /= d;
        }
    }
    if (n > 1)
        factorization.push_back(n);
    return factorization;
}

vector<int> prime_factorization(int n)
{
    vector<int> fact;
    int number = n - 1;
    for (int i = 2; i * i <= number; i++)
    { // O(n)
        if (number % i == 0)
            fact.push_back(i);
        while (number % i == 0)
            number /= i;
    }
    if (number > 2)
        fact.push_back(number);

    return fact;
}

int calculate_phi(int n)
{
    int result = n;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

// Here p is prime number
pair<int, int> generator(int p)
{
    // phi(p) = p-1
    // Factorize p-1
    vector<int> factors;
    int phi = p - 1;
    int n = phi;

    int total = calculate_phi(phi);
    // for (int i = 2; i < phi; i++)
    //     if (gcd(i, phi) == 1)
    //         total++;

    // Getting all prime factors of phi
    while (n % 2 == 0)
    {
        factors.push_back(2);
        n /= 2;
    }
    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0)
        {
            factors.push_back(i);
            n /= i;
        }
    if (n > 1)
        factors.push_back(n);
    // factors = prime_factorization(n);

    // for (int fact : factors)
    //     cout << fact << ' ';
    // cout << endl;

    for (int res = 2; res <= p; ++res)
    {
        bool ok = true;
        // Calculate res^phi/(factors[i]) % n
        for (int factor : factors)
        {
            long long pow = powmod(res, phi / factor, p);
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
    int n;
    cin >> n;

    // for (int prime : primes)
    //     cout << prime << ' ';
    // cout << endl;
    pair<int, int> ans = generator(n);
    cout << ans.first << ' ' << ans.second << endl;

    return 0;
}