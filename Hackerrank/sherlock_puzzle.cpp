#include <bits/stdc++.h>

using namespace std;

int main()
{
    int k;
    string s;

    cin >> k >> s;

    int count0 = 0;
    int count1 = 0;
    for (char c : s)
    {
        if (c == '0')
            count0++;
        else
            count1++;
    }

    int s_idx = 0;
    int curr_0 = count0;
    int curr_1 = count1;
    while (s_idx != s.length())
    {
        if (2 * curr_0 <= 3 * curr_1)
            break;

        if (s[s_idx] == '0')
            curr_0--;
        else
            curr_1--;

        s_idx++;
    }

    if (s_idx != s.length())
        cout << s.substr(s_idx, s.length() - s_idx);

    return 0;
}