#include <bits/stdc++.h>

using namespace std;

vector<string> gen_with_len(int len)
{
    if (len == 1)
        return vector<string>{"9"};

    vector<string> testing = gen_with_len(len - 1);
    vector<string> ans;
    for (string s : testing)
    {
        ans.push_back(s + '0');
        ans.push_back(s + '9');
    }

    return ans;
}

vector<long long> initialize()
{
    vector<long long> ans;
    for (int l = 1; l <= 13; l++)
    {
        vector<string> temp = gen_with_len(l);
        for (string s : temp)
            ans.push_back(stoll(s));
    }

    return ans;
}

int main()
{
    // int t;
    // cin >> t;

    // while (t--)
    // {
    //     int n;
    //     cin >> n;
    // }
    vector<long long> pairs = initialize();

    for (int k = 1; k <= 500; k++)
    {
        bool found = false;
        for (long long i : pairs)
        {
            if (i % k == 0)
            {
                found = true;
                cout << k << " --> " << i << endl;
                break;
            }
        }
        if (!found)
        {
            cout << "NOT FOUND: " << k << endl;
            break;
        }
    }

    return 0;
}

// 9

// 90
// 99

// 900
// 909
// 990
// 999