#include <bits/stdc++.h>

using namespace std;

const int N = 4;

int arr[N] = {1, 2, 0, 2};
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

        segment_tree[v] = segment_tree[2 * v] + segment_tree[2 * v + 1];
    }
}

int find_sum(int v, int l, int r, int x, int y)
{
    if (x > y)
        return 0;
    if (l == x && r == y)
        return segment_tree[v];

    int mid = (l + r) >> 1;

    return find_sum(2 * v, l, mid, x, min(mid, y)) + find_sum(2 * v + 1, mid + 1, r, max(mid + 1, x), y);
}

int find_prefix(int v, int l, int r, int q)
{
    if (l == r)
        return l;
    int mid = (l + r) >> 1;
    if (segment_tree[2 * v] >= q)
        return find_prefix(2 * v, l, mid, q);
    return find_prefix(2 * v + 1, mid + 1, r, q - segment_tree[2 * v]);
}

int main()
{
    build(1, 0, N - 1);

    int q = 5;

    cout << find_prefix(1, 0, N - 1, q) << endl;

    return 0;
}