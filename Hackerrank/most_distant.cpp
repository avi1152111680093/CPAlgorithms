#include <bits/stdc++.h>

typedef long long LL;

double distance(LL a, LL b)
{
    if (b == 0)
        return a;
    if (a == 0)
        return b;
    return sqrt(a * a + b * b);
}

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> dots(n);

    int min_x = INT_MAX, max_x = INT_MIN, min_y = INT_MAX, max_y = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        cin >> dots[i].first >> dots[i].second;

        if (dots[i].second == 0)
        {
            min_x = min(min_x, dots[i].first);
            max_x = max(max_x, dots[i].first);
        }
        if (dots[i].first == 0)
        {
            min_y = min(min_y, dots[i].second);
            max_y = max(max_y, dots[i].second);
        }
    }

    double ans = 0;
    ans = max(ans, distance(min_x, max_y));
    ans = max(ans, (double)abs(min_x - max_x));
    ans = max(ans, distance(min_x, min_y));
    ans = max(ans, (double)abs(min_y - max_y));
    ans = max(ans, distance(min_y, max_x));
    ans = max(ans, distance(max_y, max_x));

    cout << fixed << setprecision(12);
    cout << ans << endl;

    return 0;
}