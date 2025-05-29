#include <bits/stdc++.h>
#define MOD 1000000000

typedef long long LL;

using namespace std;

LL ncr[2001][1000];

void initialize()
{
    for (int i = 0; i < 2001; i++)
        for (int j = 0; j <= i; j++)
        {
            if (i == j || j == 0)
                ncr[i][j] = 1;
            else
                ncr[i][j] = (ncr[i - 1][j - 1] + ncr[i - 1][j]) % MOD;
        }
}

int solve(int n, int m)
{
    LL ans = ncr[n + m - 1][m];

    return ans;
}

int main()
{
    initialize();

    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        cout << solve(n, k) << endl;
    }
    // cout << factorials[3] << endl;
    // cout << inverse_factorials[3] << endl;

    return 0;
}