#include <bits/stdc++.h>

typedef long long LL;

using namespace std;

vector<pair<LL, LL>> prime_factors(LL n)
{
    vector<pair<LL, LL>> factors;
    pair<LL, LL> temp;
    temp.first = 2;
    temp.second = 0;
    while (n % 2 == 0)
    {
        temp.second++;
        n /= 2;
    }
    if (temp.second != 0)
        factors.push_back(temp);

    for (int i = 3; i * i <= n; i += 2)
    {
        temp.first = i;
        temp.second = 0;
        while (n % i == 0)
        {
            temp.second++;
            n /= i;
        }
        if (temp.second != 0)
            factors.push_back(temp);
    }

    if (n > 1)
        factors.push_back({n, 1});

    return factors;
}

LL sum_digits(LL n)
{
    string s = to_string(n);
    LL sum = 0;
    for (char c : s)
        sum += (c - '0');
    return sum;
}

int main()
{
    LL n;
    cin >> n;

    vector<pair<LL, LL>> factors = prime_factors(n);

    LL sum = 0;
    for (pair<LL, LL> factor : factors)
        sum += (sum_digits(factor.first) * factor.second);

    if (factors.size() == 1 && factors[0].second == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    if (sum_digits(n) == sum)
        cout << 1 << endl;
    else
        cout << 0 << endl;

    return 0;
}