#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;

string add(string a, string b)
{
    string ans = "";
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    // cout << a << ' ' << b << endl;
    // cout << a.size() << ' ' << b.size() << endl;
    if (b.size() < a.size())
        swap(a, b);
    // cout << a << ' ' << b << endl;
    // cout << a.size() << ' ' << b.size() << endl;

    int t2 = b.size() - a.size();
    int t = abs(t2);
    for (int i = 0; i < t; i++)
        a += '0';

    int carry = 0;

    for (int i = 0; i < a.size(); i++)
    {
        int temp = carry + (a[i] - '0') + (b[i] - '0');
        int b = temp % 10;
        carry = (temp - b) / 10;
        ans += ('0' + b);
    }
    if (carry != 0)
        ans += ('0' + carry);

    reverse(ans.begin(), ans.end());
    return ans;
}

string multiply(string a, char b)
{
    string ans = "";
    reverse(a.begin(), a.end());

    int carry = 0;

    for (int i = 0; i < a.size(); i++)
    {
        int temp = (a[i] - '0') * (b - '0') + carry;
        int b = temp % 10;
        carry = (temp - b) / 10;
        ans += ('0' + b);
    }
    if (carry != 0)
        ans += ('0' + carry);
    reverse(ans.begin(), ans.end());

    return ans;
}

string multiply(string a, string b)
{
    // reverse(a.begin(), a.end());
    // reverse(b.begin(), b.end());
    string ans = "0";
    for (int i = b.size() - 1; i >= 0; i--)
    {
        string temp = multiply(a, b[i]);
        for (int j = 0; j < b.size() - 1 - i; j++)
            temp += '0';

        ans = add(ans, temp);
    }

    return ans;
}

string divide_by_2(string s)
{
    if (s == "1")
        return "0";

    string ans = "";
    int carry = 0;

    for (int i = 0; i < s.size(); i++)
    {
        int d = (10 * carry) + (s[i] - '0');
        carry = (s[i] - '0') % 2;
        int q = d / 2;

        ans += ('0' + q);
    }

    if (ans[0] == '0')
        ans.erase(ans.begin());

    return ans;
}

string str_mod(string s, long long mod)
{
    long long carry = 0;

    for (int i = 0; i < s.size(); i++)
    {
        long long d = (10 * carry) + (s[i] - '0');
        // cout << (10 * carry) << endl;
        carry = d % mod;
        // cout << d << endl;
        // cout << carry << endl;
        // cout << "----" << endl;
    }

    return to_string(carry % mod);
}

string powmod(string a, string b)
{
    a = str_mod(a, MOD);
    b = str_mod(b, MOD - 1);
    string ans = "1";
    string pow = a;
    while (b != "0")
    {
        if ((b[b.size() - 1] - '0') % 2 == 1)
        {
            // cout << "Multiply " << ans << ',' << pow << endl;
            ans = multiply(ans, pow);
            ans = str_mod(ans, MOD);
        }

        pow = multiply(pow, pow);
        pow = str_mod(pow, MOD);

        b = divide_by_2(b);
        // cout << b << endl;
    }

    return ans;
}

int main()
{
    // int t;
    // cin >> t;

    // while (t--)
    // {
    //     string a, b;
    //     cin >> a >> b;
    //     cout << powmod(a, b) << endl;
    // }

    cout << multiply("22623794575945250417126212493990554565764542857950849806283758943468793303356805520205876530641101778795848533695314046548457340007352733237182206385566019060546930233873476428834026187042221656627357823590961794066909872458358078108650773450977065128248635502389638302084217075308956194677752326008879839371058510788722038403891292667062583071745708548966375385311501371567546166680806538276632448177370549475410763270269505952885947795594016006334662481264670116795339498317355278414072", "19645") << endl;

    // cout << multiply("1", "1256") << endl;
    // cout << divide_by_2("909") << endl;
    // cout << str_mod("25698321988384", 1000000007) << endl;
    // cout << str_mod("700000004", 1000000007) << endl;
    // cout << str_mod("239", 239) << endl;

    // int n = 7000000040;
    // cout << n << endl;

    return 0;
}