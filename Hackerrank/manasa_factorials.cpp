#include <bits/stdc++.h>

typedef long long LL;

using namespace std;

LL calculate_zeros(LL n)
{
    LL ans = 0;
    LL i = 5;
    while (n / i)
    {
        ans += (n / i);
        i *= 5;
    }

    return ans;
}

LL solve(LL n)
{
    LL t = 4 * n / 5;
    LL low = t * 5;
    LL high = n * 5;

    while (low <= high)
    {
        LL mid = (low + high) / 2;
        // t = mid / 5;
        // mid = t * 5;

        LL ans = calculate_zeros(mid);
        LL prev_ans = calculate_zeros(mid - 1);
        LL next_ans = calculate_zeros(mid + 1);

        // cout << prev_ans << ' ' << ans << ' ' << next_ans << endl;

        if (ans == n)
            return mid;
        if (prev_ans < n && ans >= n)
            return mid;
        else if (ans < n && next_ans >= n)
            return mid + 1;
        else if (ans < n)
            low = mid + 1;
        else if (ans > n)
            high = mid - 1;
    }

    return 0;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        LL n;
        cin >> n;

        LL temp = solve(n);
        cout << temp - temp % 5 << endl;
    }

    return 0;
}