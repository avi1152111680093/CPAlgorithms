#include <bits/stdc++.h>
#include <math.h>

using namespace std;

long long int log_a_to_base_b(long long int a, long long int b)
{
    return log2(a) / log2(b);
}

int main()
{
    long long int n, a, b;

    cin >> n;

    while (n--)
    {
        cin >> a >> b;

        if (b == 1)
        {
            cout << a << endl;
            return 0;
        }

        long long int ans = 0;
        while (a != 0)
        {
            if (a < b)
            {
                ans += a;
                break;
            }
            long long int k = log_a_to_base_b(a, b);
            a -= int(pow(b, k));
            ans++;
        }

        cout << ans << endl;
    }

    return 0;
}