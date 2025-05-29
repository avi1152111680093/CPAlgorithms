#include <bits/stdc++.h>

using namespace std;

int main()
{
    double pi = acos(-1.0);

    double min = 1;

    for (int den = 1; den <= (int)1e8; den++)
    {
        int num = (int)round(den * pi);
        double distance = abs(pi - (double)num / den);
        if (distance < min)
        {
            min = distance;
            printf("%d/%d distance=%.10e\n", num, den, distance);
        }
    }

    return 0;
}