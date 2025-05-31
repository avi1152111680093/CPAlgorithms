#include <bits/stdc++.h>

typedef long long LL;

using namespace std;

LL solve(LL a, LL b)
{
    LL ans = 2 % b;
    for (int i = 1; i <= a; i++)
    {

        ans = (ans * ans) % b;
    }

    return ans % b;
}

int main()
{
    LL a, b;
    cin >> a >> b;

    cout << solve(a, b) << endl;

    return 0;
}