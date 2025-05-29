#include <bits/stdc++.h>

typedef long long LL;

using namespace std;

int gcd(int a, int b)
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
    int n, m;
    cin >> n >> m;

    int arr[n][m];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    int ans = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            int dp[201][201];
            for (int k = i; k < n; k++)
                for (int l = j; l < m; l++)
                {
                    if (i == k && j == l)
                        dp[k][l] = arr[k][l];
                    else if (i == k)
                        dp[k][l] = gcd(dp[k][l - 1], arr[k][l]);
                    else if (j == l)
                        dp[k][l] = gcd(dp[k - 1][l], arr[k][l]);
                    else
                        dp[k][l] = gcd(gcd(dp[k - 1][l], dp[k][l - 1]), arr[k][l]);

                    if (dp[k][l] > 1)
                        ans = max(ans, (k - i + 1) * (l - j + 1));
                    else
                        break;
                }
        }

    cout << ans << endl;

    return 0;
}