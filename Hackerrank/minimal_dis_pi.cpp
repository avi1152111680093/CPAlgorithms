#include <bits/stdc++.h>
#include <math.h>

using namespace std;

// 81/26 = 0.02620804
// 82/26 = 0.0122535
// 83/26 = 0.05071504
// 482480 1196809

std::pair<int, int> findBestApprox(int minD, int maxD)
{
    const double pi = M_PI;
    double minDiff = std::numeric_limits<double>::max();
    int bestN = 0, bestD = 1;

    for (int d = minD; d <= maxD; ++d)
    {
        double piTimesD = pi * d;

        // Only round once per d to avoid multiple expensive calls
        int n1 = static_cast<int>(piTimesD);       // floor
        int n2 = static_cast<int>(piTimesD + 1.0); // ceiling without using std::ceil

        for (int n : {n1, n2})
        {
            double approx = static_cast<double>(n) / d;
            double diff = std::abs(approx - pi);

            if (diff < minDiff)
            {
                minDiff = diff;
                bestN = n;
                bestD = d;
            }
        }
    }

    return {bestN, bestD};
}

int main()
{
    // cout << M_PI << endl;
    // int t;
    // cin >> t;
    // M_PI

    long long mini, maxi;
    cin >> mini >> maxi;

    // 25 % 7 = 4
    // 25 + (7-4)

    // long long temp = mini % 7;

    // long long k = mini + 7 - temp;

    // if (k <= maxi)
    // {
    //     int multiple = k / 7;
    //     cout << 22 * multiple << '/' << k << endl;
    //     return 0;
    // }

    // double ans = INT_MAX;
    // long long ans_num;
    // long long ans_den;
    // for (int i = mini; i <= maxi; i++)
    // {
    //     double t1 = i * M_PI;
    //     long long t2 = nearbyint(t1);

    //     double t3 = (double)t2 / (double)i;
    //     if (abs(t3 - M_PI) < ans)
    //     {
    //         ans = abs(t3 - M_PI);
    //         ans_num = t2;
    //         ans_den = i;
    //     }
    // }

    // cout << ans_num << '/' << ans_den << endl;

    auto temp = findBestApprox(mini, maxi);
    cout << temp.first << '/' << temp.second << endl;

    return 0;
}