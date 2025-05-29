#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int a, b, c;

        cin >> a >> b >> c;

        if (c > max(a, b))
        {
            cout << "NO\n";
            continue;
        }

        if (c % (a - b) == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}