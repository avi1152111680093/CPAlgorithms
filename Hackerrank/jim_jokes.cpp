#include <bits/stdc++.h>

typedef long long LL;

using namespace std;

int value(int month, int day)
{
    int base = month;
    int number = day;

    string str_number = to_string(number);
    for (char c : str_number)
    {
        if (c - '0' >= base)
            return -1;
    }

    int ans = 0;
    int mult_factor = 1;
    while (number)
    {
        int last_dig = number % 10;
        ans += (last_dig * mult_factor);
        mult_factor *= base;
        number /= 10;
    }

    return ans;
}

int main()
{
    int t;
    cin >> t;

    unordered_map<LL, LL> count;

    LL ans = 0;
    while (t--)
    {
        int month, day;
        cin >> month >> day;
        int base_val = value(month, day);

        if (base_val != -1)
        {
            if (count.find(base_val) == count.end())
                count[base_val] = 1;
            else
                count[base_val]++;
        }
    }
    for (auto elem : count)
    {
        LL temp = (elem.second * (elem.second - 1));
        temp /= 2;
        ans += temp;
    }

    cout << ans << endl;

    return 0;
}