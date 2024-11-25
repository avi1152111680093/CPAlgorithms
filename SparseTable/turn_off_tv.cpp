#include <bits/stdc++.h>

using namespace std;

const int MN = 6e5;
int start_end[MN];
int prefix_sum[MN];
int sparse_table[MN][20];

// Querying Sparse Table
int find_min(int l, int r)
{
    int k = log2(r - l + 1);
    return min(sparse_table[l][k], sparse_table[r - (1 << k) + 1][k]);
}
// ---------------------

int main()
{
    const int n = 3;

    int a[n] = {1, 2, 3};
    int b[n] = {2, 3, 4};

    for (int i = 0; i < n; i++)
    {
        start_end[a[i]] += 1;
        start_end[b[i] + 1] -= 1;
    }

    // for (int i = 0; i < 8; i++)
    //     cout << start_end[i] << ' ';
    // cout << endl;

    for (int i = 1; i < MN; i++)
        prefix_sum[i] = prefix_sum[i - 1] + start_end[i];

    // for (int i = 0; i < 8; i++)
    //     cout << prefix_sum[i] << ' ';
    // cout << endl;

    // Initializing Sparse Table
    for (int i = 0; i < MN; i++)
        sparse_table[i][0] = prefix_sum[i];
    for (int j = 1; j < int(log2(MN)) + 1; j++)
        for (int i = 0; i < MN - (1 << (j - 1)); i++)
            sparse_table[i][j] = min(sparse_table[i][j - 1], sparse_table[i + (1 << (j - 1))][j - 1]);
    // -------------------------

    for (int i = 0; i < n; i++)
    {
        int s = a[i];
        int e = b[i];

        if (!(find_min(s, e) <= 1))
        {
            printf("(%d,%d) is redundant TV set!", s, e);
            return 0;
        }
    }
    printf("No redundant TV set!");

    return 0;
}