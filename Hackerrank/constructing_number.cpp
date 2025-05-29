#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        long long numbers[n];

        for (int i = 0; i < n; i++)
            cin >> numbers[i];

        long long digit_sum = 0;
        for (long long num : numbers)
        {
            string str_num = to_string(num);
            for (char c : str_num)
                digit_sum += (c - '0');
        }

        if (digit_sum % 3 == 0)
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}