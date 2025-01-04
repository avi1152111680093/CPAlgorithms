#include <bits/stdc++.h>

using namespace std;

const int N = 6;
int arr[N] = {5, 2, 4, 0, 1, -3};

// 5 3 3 3 -3 -3

int segment_tree[4 * N];
bool filled[4 * N];

void build(int v, int l, int r)
{
    if (l == r)
    {
        filled[v] = true;
        segment_tree[v] = arr[l];
    }
    else
    {
        int mid = (l + r) >> 1;

        build(2 * v, l, mid);
        build(2 * v + 1, mid + 1, r);

        if (filled[2 * v] && filled[2 * v + 1] && segment_tree[2 * v] == segment_tree[2 * v + 1])
        {
            filled[v] = true;
            segment_tree[v] = segment_tree[2 * v];
        }
        else
            filled[v] = false;
    }
}

void update(int v, int l, int r, int x, int y, int val)
{
    if (x > y)
        return;
    if (l == x && r == y)
    {
        filled[v] = true;
        segment_tree[v] = val;
    }
    else
    {
        if (filled[v])
        {
            segment_tree[2 * v] = segment_tree[2 * v + 1] = segment_tree[v];
            filled[v] = false;
            filled[2 * v] = filled[2 * v + 1] = true;
        }

        int mid = (l + r) >> 1;

        update(2 * v, l, mid, x, min(y, mid), val);
        update(2 * v + 1, mid + 1, r, max(x, mid + 1), y, val);
    }
}

int query(int v, int l, int r, int idx)
{
    if (filled[v] && (l <= idx && idx <= r))
        return segment_tree[v];

    int mid = (l + r) >> 1;

    if (idx <= mid)
        return query(2 * v, l, mid, idx);
    return query(2 * v + 1, mid + 1, r, idx);
}

int main()
{
    build(1, 0, N - 1);

    update(1, 0, N - 1, 2, 4, -3);
    update(1, 0, N - 1, 1, 3, 3);

    cout << query(1, 0, N - 1, 5) << endl;

    return 0;
}