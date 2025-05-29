// We are required to find the modular inverse of the number a mod m
#include <bits/stdc++.h>

using namespace std;

int extended_euclidean(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = extended_euclidean(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);

    return d;
}

int main()
{
    int a = 90;
    int m = 7;
    int x, y;

    int g = extended_euclidean(a, m, x, y);

    if (g != 1)
        cout << "No Solution" << endl;
    else
    {
        x = (x % m + m) % m;
        cout << x << endl;
    }

    return 0;
}