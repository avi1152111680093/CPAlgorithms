#include <bits/stdc++.h>

using namespace std;

vector<long long> trial_division2(long long n)
{
    vector<long long> factorization;
    while (n % 2 == 0)
    {
        factorization.push_back(2);
        n /= 2;
    }
    for (long long d = 3; d * d <= n; d += 2)
    {
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

int main()
{
    vector<long long> factors = trial_division2(900);

    for (long long factor : factors)
    {
        cout << factor << ' ';
    }
    cout << endl;

    return 0;
}
