#include <bits/stdc++.h>

using namespace std;

const int N = 6;

int arr[N] = {1, 2, 4, 6, -1, 0};
int segment_tree[4 * N];

void build(int v, int l, int r)
{
    if (l == r)
        segment_tree[v] = arr[l];
    else
    {
        int mid = (l + r) / 2;

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
    int mid = (l + r) / 2;

    return find_sum(2 * v, l, mid, x, min(mid, y)) + find_sum(2 * v + 1, mid + 1, r, max(mid + 1, x), y);
}

void update(int v, int l, int r, int pos, int new_val)
{
    if (l == r)
        segment_tree[v] = new_val;
    else
    {
        int mid = (l + r) / 2;

        if (pos <= mid)
            update(2 * v, l, mid, pos, new_val);
        else
            update(2 * v + 1, mid + 1, r, pos, new_val);

        segment_tree[v] = segment_tree[2 * v] + segment_tree[2 * v + 1];
    }
}

int main()
{
    build(1, 0, N - 1);

    update(1, 0, N - 1, 4, -5);
    cout << find_sum(1, 0, N - 1, 2, 4) << endl;

    return 0;
}