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

string division(string str, int n)
{
    string ans = "";
    LL carry = 0;

    for (int i = 0; i < str.size(); i++)
    {
        LL d = (10 * carry) + (str[i] - '0');
        carry = d % n;
        LL q = d / n;

        cout << d << endl;
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
        carry = d % mod;
    }

    return to_string(carry % mod);
}

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

std::string subtractStrings(std::string num1, std::string num2)
{
    if (num1.length() < num2.length() || (num1.length() == num2.length() && num1 < num2))
    {
        std::swap(num1, num2);
    }

    std::string result = "";
    int borrow = 0;
    int diff = num1.length() - num2.length();

    for (int i = num2.length() - 1; i >= 0; i--)
    {
        int sub = (num1[i + diff] - '0') - (num2[i] - '0') - borrow;
        if (sub < 0)
        {
            sub += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }
        result += std::to_string(sub);
    }

    for (int i = diff - 1; i >= 0; i--)
    {
        if (num1[i] == '0' && borrow)
        {
            result += '9';
        }
        else
        {
            int sub = (num1[i] - '0') - borrow;
            if (sub < 0)
            {
                sub += 10;
                borrow = 1;
            }
            else
            {
                borrow = 0;
            }
            result += std::to_string(sub);
        }
    }

    std::reverse(result.begin(), result.end());

    int i = 0;
    while (i < result.length() - 1 && result[i] == '0')
    {
        i++;
    }
    return result.substr(i);
}

string solve(string n, int p)
{
    string temp2 = "1";
    string totNums = add(n, "1");

    while (division(n, p) != "")
    {
        string smod = str_mod(n, p);
        string temp1 = add(smod, "1");

        temp2 = multiply(temp2, temp1);

        n = division(n, p);

        cout << n << endl;
    }
    if (n != "")
        temp2 = multiply(temp2, add(n, "1"));

    cout << totNums << endl;

    return subtractStrings(totNums, temp2);
}

int main()
{
    // int t;
    // cin >> t;

    // while (t--)
    // {
    //     string n;
    //     int p;

    //     cin >> n >> p;

    //     string temp2 = "1";
    //     string totNums = add(n, "1");

    //     while (division(n, p) != "")
    //     {
    //         string smod = str_mod(n, p);
    //         string temp1 = add(smod, "1");

    //         temp2 = multiply(temp2, temp1);

    //         n = division(n, p);
    //     }
    //     if (n != "")
    //         temp2 = multiply(temp2, add(n, "1"));

    //     cout << subtractStrings(totNums, temp2) << endl;
    // }

    // solve("45078080084833915853071488226474284027359334887199063993840204518796903836813653768480290768840354861812283604986736296958505805912652759313243875602610575686783834447319839176810497317315493041367169071424922242979392056083663490702076010061373139236058437421032960868119583444445383192428605404624271091535309774917985030902351396298686787925356024073526841807738159019553285944784283053529257194981590842602739782310168228436050987980819154991664605035774850517597809605493080091816050270545463172", 224284387);
    // cout << division("45078080084833915853071488226474284027359334887199063993840204518796903836813653768480290768840354861812283604986736296958505805912652759313243875602610575686783834447319839176810497317315493041367169071424922242979392056083663490702076010061373139236058437421032960868119583444445383192428605404624271091535309774917985030902351396298686787925356024073526841807738159019553285944784283053529257194981590842602739782310168228436050987980819154991664605035774850517597809605493080091816050270545463172", 224284387) << endl;
    cout << division("56789876598763456", 224284387) << endl;

    return 0;
}