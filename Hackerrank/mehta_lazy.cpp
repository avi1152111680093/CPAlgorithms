#include <bits/stdc++.h>

typedef long long LL;

using namespace std;

LL gcd(LL a, LL b)
{
    while (b)
    {
        a %= b;
        swap(a, b);
    }

    return a;
}

unordered_map<int, int> prime_factorization(int n)
{
    unordered_map<int, int> ans;
    int temp = 0;
    while (n % 2 == 0)
    {
        temp++;
        n /= 2;
    }
    if (temp)
        ans[2] = temp;

    for (int i = 3; i * i <= n; i += 2)
    {
        temp = 0;
        while (n % i == 0)
        {
            temp++;
            n /= i;
        }
        if (temp)
            ans[i] = temp;
    }

    if (n > 1)
        ans[n] = 1;

    return ans;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        unordered_map<int, int> factorization = prime_factorization(n);

        LL temp = 1;
        for (auto factors : factorization)
            if (factors.first != 2)
                temp *= ((factors.second / 2) + 1);
        temp--;
        if (factorization.find(2) != factorization.end())
            temp = (temp + 1) * (factorization[2] / 2);
        else
            temp = 0;

        LL temp2 = (long long)sqrt(n);
        if (temp2 * temp2 == n)
            temp--;

        long long int denominator = 1;
        for (auto factors : factorization)
            denominator *= (factors.second + 1);
        denominator--;

        // 9
        // 3 = 2
        // temp = 1

        // cout << (factorization.find(2) == factorization.end()) << endl;

        // cout << denominator << endl;
        // // 36
        // // 2 = 2
        // // 3 = 2
        LL g = gcd(temp, denominator);

        // 9
        // 2=0
        // 3=2

        if (factorization.find(2) == factorization.end())
        {
            cout << 0 << endl;
            continue;
        }
        if (temp == 0)
            cout << 0 << endl;
        else
            cout << temp / g << '/' << denominator / g << endl;
    }
    return 0;
}