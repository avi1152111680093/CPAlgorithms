#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int t;
    cin >> t;

    while (t--)
    {
        int x, y;
        cin >> x >> y;

        if (x > y)
        {
            cout << "Odd\n"
                 << endl;
            continue;
        }
        if (arr[x] == 0)
        {
            cout << "Odd\n";
            continue;
        }
        if (arr[x - 1] % 2 == 0)
            cout << "Even\n";
        else
            cout << "Odd\n";
    }

    return 0;
}
