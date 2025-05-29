#include <bits/stdc++.h>
#define PP 2000000

typedef long long LL;

using namespace std;

vector<long long> W;
vector<long long> F;
bool P[PP];

LL solve(LL n)
{
    LL ans = 0;
    for (int i = 0; i < W.size(); i++)
    {
        while (n % W[i] == 0)
        {
            ans += n;
            n /= W[i];
        }
    }
    // while (n % 2 == 0)
    // {
    //     ans += n;
    //     n /= 2;
    // }
    // for (int i = 3; i * i <= n; i += 2)
    // {
    //     while (n % i == 0)
    //     {
    //         ans += n;
    //         n /= i;
    //     }
    // }
    if (n > 1)
        ans += n;

    return ans + 1;
}

int main()
{
    for (long long i = 2; i < PP; i++)
    {
        if (P[i])
            continue;
        W.push_back(i);
        for (long long j = i * i; j < PP; j += i)
        {
            P[j] = true;
        }
    }

    int t;
    cin >> t;

    LL ans = 0;
    while (t--)
    {
        LL n;
        cin >> n;
        ans += solve(n);
    }
    cout << ans << endl;

    return 0;
}