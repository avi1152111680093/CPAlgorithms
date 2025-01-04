#include <bits/stdc++.h>

using namespace std;

const int N = 8;

int arr[N] = {1, 2, 0, -2, -1, 9, 4, 6};
int segment_tree[4 * N];

void build(int v, int l, int r)
{
    if (l == r)
        segment_tree[v] = arr[l];
    else
    {
        int mid = (l + r) >> 1;

        build(2 * v, l, mid);
        build(2 * v + 1, mid + 1, r);

        segment_tree[v] = max(segment_tree[2 * v], segment_tree[2 * v + 1]);
    }
}

int find_max(int v, int l, int r, int x, int y)
{
    if (x > y)
        return INT_MIN;
    if (l == x && r == y)
        return segment_tree[v];

    int mid = (l + r) >> 1;

    return max(find_max(2 * v, l, mid, x, min(mid, y)), find_max(2 * v + 1, mid + 1, r, max(mid + 1, x), y));
}

// max_prefix(int v, int l, int r, int x, int y, int k)
// returns the max prefix from x to y which is >= k
int max_prefix(int v, int l, int r, int x, int y, int k)
{
    // if (l > y && r < x)
    if (segment_tree[v] <= k)
        return -1;

    if (l == r)
        return l;

    int mid = (l + r) >> 1;

    int left_prefix = max_prefix(2 * v, l, mid, x, min(mid, y), k);
    int right_prefix = max_prefix(2 * v + 1, mid + 1, r, max(x, mid + 1), y, k);

    if (left_prefix != -1)
        return left_prefix;

    return right_prefix;
    // int left_max = segment_tree[2 * v];
    // int right_max = segment_tree[2 * v + 1];

    // // Max is in the left tree
    // if (left_max >= k)
    //     return max_prefix(2 * v, l, mid, x, min(mid, y), k);
    // // if (right_max >= k)
    // return max_prefix(2 * v + 1, mid + 1, r, max(x, mid + 1), y, k);
    // return max_prefix(2 * v, l, mid, );
}

int main()
{
    build(1, 0, N - 1);

    // cout << find_max(1, 0, N - 1, 2, 5) << endl;
    cout << max_prefix(1, 0, N - 1, 2, 5, 2) << endl;
    // cout << min(1, 3) << endl;

    return 0;
}