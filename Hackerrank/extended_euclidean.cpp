#include <iostream>

// Function to implement the Extended Euclidean Algorithm
int extended_euclidean(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int gcd = extended_euclidean(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}

// Extended Euclidean Algorithm
int modinv(int a, int m)
{
    int m0 = m, x0 = 0, x1 = 1;
    while (a > 1)
    {
        int q = a / m;
        int t = m;

        m = a % m, a = t;
        t = x0;

        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0)
        x1 += m0;

    return x1;
}

int main()
{
    int a = 0;
    int b = 0;

    // You can assign values to a and b here if needed
    a = 5;
    b = 10;

    return 0;
}
