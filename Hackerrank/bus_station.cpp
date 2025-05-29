#include <bits/stdc++.h>

typedef long long LL;

using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];

    unordered_set<LL> cache;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    LL prefix_sum[n];
    prefix_sum[0] = arr[0];
    cache.insert(prefix_sum[0]);
    for (int i = 1; i < n; i++)
    {
        prefix_sum[i] = prefix_sum[i - 1] + arr[i];
        cache.insert(prefix_sum[i]);
    }

    vector<LL> ans;
    for (int possible_size : prefix_sum)
    {
        if (prefix_sum[n - 1] % possible_size == 0)
        {
            bool present = true;
            for (int i = 2; i < prefix_sum[n - 1] / possible_size; i++)
            {
                if (cache.find(possible_size * i) == cache.end())
                {
                    present = false;
                    break;
                }
            }
            if (present)
                ans.push_back(possible_size);
        }
    }

    for (LL bus_size : ans)
        cout << bus_size << ' ';
    cout << endl;

    return 0;
}