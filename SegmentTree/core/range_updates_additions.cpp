#include <bits/stdc++.h>

using namespace std;

const int N = 6;
int arr[N] = {5, 2, 4, 0, 1, -3};

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

        segment_tree[v] = 0;
    }
}

void query_add(int v, int l, int r, int x, int y, int val)
{
    if (x > y)
        return;
    if (l == x && r == y)
    {
        segment_tree[v] += val;
        return;
    }

    int mid = (l + r) >> 1;

    query_add(2 * v, l, mid, x, min(mid, y), val);
    query_add(2 * v + 1, mid + 1, r, max(x, mid + 1), y, val);
}

int get_idx(int v, int l, int r, int idx)
{
    if (l == r)
        return segment_tree[v];

    int mid = (l + r) >> 1;

    if (idx <= mid)
        return segment_tree[v] + get_idx(2 * v, l, mid, idx);
    return segment_tree[v] + get_idx(2 * v + 1, mid + 1, r, idx);
}

void print_arr(int v, int l, int r, int val = 0)
{
    if (l == r)
    {
        cout << segment_tree[v] + val << ' ';
        return;
    }

    int mid = (l + r) >> 1;
    print_arr(2 * v, l, mid, segment_tree[v] + val);
    print_arr(2 * v + 1, mid + 1, r, segment_tree[v] + val);
}

int main()
{
    build(1, 0, N - 1);

    query_add(1, 0, N - 1, 2, 4, 3);
    query_add(1, 0, N - 1, 1, 3, -1);

    cout << get_idx(1, 0, N - 1, 2) << endl;

    // print_arr(1, 0, N - 1);
    // cout << endl;

    return 0;
}