#include <bits/stdc++.h>

using namespace std;

const int N = 5;

int arr[N] = {5, 0, 0, 1, 0};
int segment_tree[4 * N];

void build(int v, int l, int r)
{
    if (l == r)
        segment_tree[v] = arr[l] == 0 ? 1 : 0;
    else
    {
        int mid = (l + r) >> 1;

        build(2 * v, l, mid);
        build(2 * v + 1, mid + 1, r);

        segment_tree[v] = segment_tree[2 * v] + segment_tree[2 * v + 1];
    }
}

void update(int v, int l, int r, int pos, int new_val)
{
    if (l == r)
        segment_tree[v] = new_val == 0 ? 1 : 0;
    else
    {
        int mid = (l + r) >> 1;

        if (pos <= mid)
            update(2 * v, l, mid, pos, new_val);
        else
            update(2 * v + 1, mid + 1, r, pos, new_val);

        segment_tree[v] = segment_tree[2 * v] + segment_tree[2 * v + 1];
    }
}

int count_zeroes(int v, int l, int r, int x, int y)
{
    if (x > y)
        return 0;
    if (l == x && r == y)
        return segment_tree[v];
    else
    {
        int mid = (l + r) >> 1;

        return count_zeroes(2 * v, l, mid, x, min(mid, y)) + count_zeroes(2 * v + 1, mid + 1, r, max(mid + 1, x), y);
    }
}

int kth_zero(int v, int l, int r, int k)
{
    if (segment_tree[v] < k)
        return -1;
    if (l == r)
        return l;
    int mid = (l + r) >> 1;
    if (segment_tree[2 * v] >= k)
        return kth_zero(2 * v, l, mid, k);
    return kth_zero(2 * v + 1, mid + 1, r, k - segment_tree[2 * v]);
}

int main()
{
    build(1, 0, N - 1);
    cout << kth_zero(1, 0, N - 1, 3) << endl;

    return 0;
}