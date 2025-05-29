#include <iostream>
#include <vector>

using namespace std;

const int M = 1000007;

// Sieve of Eratosthenes to generate all primes up to n
vector<int> generate_primes(int n)
{
    vector<bool> is_prime(n + 1, true);
    vector<int> primes;

    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; ++i)
    {
        if (is_prime[i])
        {
            primes.push_back(i);
            for (int j = 2 * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    return primes;
}

int main()
{
    int N;
    cin >> N;

    vector<int> primes = generate_primes(N);
    long long result = 1;

    for (int p : primes)
    {
        int x = N;
        int e = 0;

        // Count exponent of prime p in N!
        while (x > 0)
        {
            x /= p;
            e += x;
        }

        result = (result * (2LL * e + 1)) % M;
    }

    cout << result << endl;
    return 0;
}
