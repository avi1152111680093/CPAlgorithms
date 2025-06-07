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

int main()
{
    LL n = 12;

    // f(k) = Number of (p,q) pairs such i.e.
    // f(12) = (3,4) = 2
    // f(1) = 1
    // vector<LL> temp;
    // for (LL i = 0; i < 1000000000; i++)
    // {
    //     temp.push_back(i);
    // }
    unordered_map<LL, LL> m;
    for (int k = 2; k <= 10000; k++)
    {
        for (int i = k + 1; i < 10000; i++)
        {
            if (gcd(k, i) == 1)
            {
                if (m.find(i * k) == m.end())
                    m[i * k] = 1;
                else
                {
                    // cout << i << ' ' << k << endl;
                    m[i * k]++;
                }
            }
            // cout << i * k << endl;
        }
    }

    // for (auto itr : m)
    //     cout << itr.first << "--->" << itr.second << endl;

    return 0;
}