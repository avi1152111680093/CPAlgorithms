#include <bits/stdc++.h>

typedef long long LL;

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        LL n;
        cin >> n;

        LL i = 1;
        while (i <= n)
        {
            LL temp = n / i;

            LL x1 = n / (temp + 1);
            LL x2 = n / temp;

            LL temp2 = x2 - x1;

            i += temp2;
        }

        cout << i << endl;
    }

    return 0;
}