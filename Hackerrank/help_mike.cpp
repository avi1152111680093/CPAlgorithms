#include <bits/stdc++.h>

typedef long long LL;

using namespace std;

LL calc_sum(LL d, LL a, LL n)
{
    LL temp = n * (2 * a + (n - 1) * d);
    return temp / 2;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        LL n1 = n / k;
        LL n2 = (2 * n - 1) / k;
        LL n3 = n2 - n1;

        cout << calc_sum(k, (k - 1) / 2, ceil(n2 / (double)2)) + calc_sum(k, k - 1, n2 / 2) - calc_sum(k, k * (n1 + 1), n3) + n3 * (n + 1) << endl;
    }

    return 0;
}