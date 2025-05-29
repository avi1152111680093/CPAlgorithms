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
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int a = abs(y2 - y1);
        int b = abs(x2 - x1);
        int d = gcd(a, b);
        cout << max(0, d - 1) << endl;
    }

    return 0;
}