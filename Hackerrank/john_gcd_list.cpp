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

LL lcm(LL a, LL b)
{
    return a * b / gcd(a, b);
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        int ans[n + 1];

        ans[n] = arr[n - 1];
        for (int i = n - 1; i > 0; i--)
            ans[i] = lcm(arr[i], arr[i - 1]);
        ans[0] = arr[0];

        for (int i = 0; i <= n; i++)
            cout << ans[i] << ' ';
        cout << endl;
    }

    return 0;
}