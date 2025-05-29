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

int main()
{
    int t;
    cin >> t;

    LL arr[t];
    for (int i = 0; i < t; i++)
        cin >> arr[i];

    LL mini = INT_MAX;
    for (int i = 0; i < t; i++)
        mini = min(mini, arr[i]);

    bool skip_mini = true;
    for (int i = 0; i < t; i++)
        if (arr[i] % mini != 0)
        {
            skip_mini = false;
            break;
        }

    if (skip_mini)
    {
        LL ans;
        bool found = true;
        for (int i = 0; i < t; i++)
            if (arr[i] != mini)
            {
                if (found)
                {
                    ans = arr[i];
                    found = false;
                }
                else
                    ans = gcd(ans, arr[i]);
            }
        cout << ans << endl;
        return 0;
    }

    LL temp = arr[0];

    for (int i = 1; i < t; i++)
    {
        LL t2 = gcd(temp, arr[i]);
        if (t2 != 1)
            temp = t2;
    }

    cout << temp << endl;

    // 2, 3, 4, 5
    // 2,5 = 1
    // 3, 12, 18, 12
    // 6

    return 0;
}