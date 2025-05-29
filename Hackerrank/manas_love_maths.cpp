#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> div_by_8;
    int k = 104;
    while (k <= 999)
    {
        div_by_8.push_back(k);
        k += 8;
    }
    vector<int> div_by_8_2;
    k = 16;
    while (k <= 99)
    {
        div_by_8_2.push_back(k);
        k += 8;
    }

    // cout << div_by_8.size() << endl;

    int t;
    cin >> t;

    while (t--)
    {
        string n;
        cin >> n;

        unordered_map<char, int> m;
        for (char c : n)
        {
            if (m.find(c) == m.end())
                m[c] = 1;
            else
                m[c]++;
        }

        if (m['0'] >= 3)
        {
            cout << "YES\n";
            continue;
        }

        if (n.size() >= 3)
        {
            bool divisible;
            for (int i : div_by_8)
            {
                divisible = true;
                string i_str = to_string(i);
                unordered_map<char, int> rollback;
                for (char i_c : i_str)
                {
                    if (m.find(i_c) == m.end() || m[i_c] == 0)
                    {
                        divisible = false;
                        break;
                    }
                    m[i_c]--;
                    if (rollback.find(i_c) == rollback.end())
                        rollback[i_c] = 1;
                    else
                        rollback[i_c]++;
                }
                for (auto r : rollback)
                    m[r.first] += r.second;
                if (divisible)
                    break;
            }

            if (divisible)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
        else if (n.size() == 2)
        {
            if (stoi(n) % 8 == 0)
            {
                cout << "YES\n";
                continue;
            }
            reverse(n.begin(), n.end());
            if (stoi(n) % 8 == 0)
            {
                cout << "YES\n";
                continue;
            }
            cout << "NO\n";
        }
        else
        {
            if (n[0] == '0' || n[0] == '8')
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }

    return 0;
}