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

pair<string, string> solve_gen(LL n)
{
    LL count = 1;
    int rem = 4;
    string q = "";
    string ans = "4";
    if (rem % n == 0)
        return {ans, to_string(rem / n)};

    while (rem % n != 0)
    {
        rem = rem * 10 + 4;
        if (rem / n)
        {
            q += to_string(rem / n);
            rem = rem % n;
        }
        count++;
        ans += '4';
    }

    return {ans, q};
}

pair<string, string> testing(LL n)
{
    string ans = "";
    int carry = 4;
    string t = "4";
    if (carry % n == 0)
        return {"4", to_string(carry / n)};

    while (carry != 0)
    {
        int d = (10 * carry) + 4;
        t += '4';
        carry = d % n;
        int q = d / n;

        // cout << d << ' ' << carry << ' ' << q << endl;

        ans += ('0' + q);
    }

    while (ans[0] == '0')
        ans.erase(ans.begin());

    return {t, ans};
}

string division(string str, int n)
{
    string ans = "";
    int carry = 0;

    for (int i = 0; i < str.size(); i++)
    {
        int d = (10 * carry) + (str[i] - '0');
        carry = d % n;
        int q = d / n;

        // cout << d << ' ' << carry << ' ' << q << endl;

        ans += ('0' + q);
    }

    if (ans[0] == '0')
        ans.erase(ans.begin());

    return ans;
}

pair<string, string> solve(LL n)
{
    if (n % 8 == 0)
    {
        pair<string, string> temp = solve(n / 8);
        LL ll_last_three;
        if (temp.second.size() <= 3)
            ll_last_three = stoll(temp.second);
        else
            ll_last_three = stoll(temp.second.substr(temp.second.length() - 3));

        LL current = ll_last_three;
        while (current % 8 != 0)
        {
            current = 10 * current;
            temp.first += '0';
            temp.second += '0';
        }

        return {temp.first, division(temp.second, 8)};
    }
    else if (n % 5 == 0)
    {
        pair<string, string> temp = solve(n / 5);
        temp.first += '0';
        temp.second += '0';

        return {temp.first, division(temp.second, 5)};
    }

    return testing(n);
}

int main()
{
    // int t;
    // cin >> t;

    // while (t--)
    // {
    //     LL i;
    //     cin >> i;

    //     pair<string, string> temp = solve(i);
    //     LL count4 = 0, count0 = 0;
    //     for (char c : temp.first)
    //     {
    //         if (c == '4')
    //             count4++;
    //         else
    //             count0++;
    //     }

    //     cout << 2 * count4 + count0 << endl;
    //     // cout << i << " ----> " << temp.first << " = " << 2 * count4 + count0 << endl;
    // }

    vector<int> input = {30628, 19645, 42058, 56053, 37011, 21427, 32427, 46278, 5443, 61055, 40046, 70692, 91613, 94410, 20048, 30161, 42891, 15321, 63877, 26200, 15636, 32172, 11296, 46673, 34045, 60840, 41509, 43329, 65352, 7428, 26990, 95980, 27073, 69049, 68385, 64085, 90476, 812, 26715, 12271, 78219, 66761, 82964, 86184, 77524, 3012, 16345, 36767, 18334, 80222, 62967, 50322, 28747, 90616, 96996, 62792, 67808, 38505, 6121, 33160, 45933, 49464, 45492, 89359, 18513, 13877, 69796, 25341, 31041, 96511, 37613, 9260, 79625, 36929, 95444, 73501, 56293, 11789, 10268, 90979, 8363, 89588, 41302, 37110, 96556, 38298, 16254, 64364, 93155, 38728, 13876, 55440, 88192, 75720, 44799, 23057, 89597, 30947, 64750, 20638};
    vector<int> output = {180, 983, 3296, 28026, 624, 408, 10800, 46224, 1814, 8141, 13348, 336, 42976, 9433, 1070, 754, 19488, 5106, 11612, 262, 2604, 2292, 67, 8484, 1237, 469, 1020, 24, 2329, 1236, 5397, 4799, 54144, 952, 4417, 3661, 45236, 168, 49, 3504, 156384, 440, 17772, 325, 2584, 300, 2797, 73532, 1496, 40110, 6900, 3594, 3168, 1381, 1392, 7637, 327, 2401, 6120, 553, 600, 4105, 3552, 29568, 3168, 6938, 8724, 50676, 7758, 31824, 18144, 309, 87, 2308, 23532, 4740, 6860, 23576, 2400, 4740, 8362, 11198, 20352, 1237, 56, 2940, 756, 32180, 601, 1565, 6936, 38, 161, 631, 432, 4192, 89596, 26520, 15, 3232};

    int fc = 0;
    for (int i = 0; i < input.size(); i++)
    {
        // cout << "BEFORE" << endl;
        pair<string, string> temp = solve(input[i]);
        // cout << "AFTER" << endl;
        LL count4 = 0, count0 = 0;
        for (char c : temp.first)
        {
            if (c == '4')
                count4++;
            else
                count0++;
        }
        if (2 * count4 + count0 == output[i])
            cout << input[i] << " SUCCESSS\n";
        else
        {
            cout << input[i] << " FAILED\n";
            fc++;
        }
    }
    cout << fc << " FAILED\n";

    // cout << solve(80).first << ' ' << solve(80).second << endl;
    // cout << testing(3929).first << ' ' << testing(3929).second << endl;

    return 0;
}