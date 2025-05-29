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

int len_dig(LL n)
{
    return to_string(n).size();
}

int main()
{
    unordered_set<LL> s = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<LL> strange_nums = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    LL tail = 9;
    LL head = 5;
    int multiplier = 2;
    while (strange_nums[tail] < 1e18)
    {
        if (len_dig(strange_nums[head] * multiplier) > multiplier)
        {
            multiplier++;
            while (len_dig(strange_nums[head - 1] * multiplier) != (multiplier - 1))
                head--;
        }
        else
        {
            LL candidate = strange_nums[head] * multiplier;
            strange_nums.push_back(candidate);
            head++;
            tail++;
        }
    }

    int t;
    cin >> t;

    while (t--)
    {
        LL l, r;
        cin >> l >> r;
        auto lb = lower_bound(strange_nums.begin(), strange_nums.end(), l);
        auto ub = upper_bound(strange_nums.begin(), strange_nums.end(), r);

        cout << distance(lb, ub) << endl;
    }

    return 0;
}