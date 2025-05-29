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
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        int g = arr[0];
        for (int i = 1; i < n; i++)
            g = gcd(g, arr[i]);

        if (g == 1)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}