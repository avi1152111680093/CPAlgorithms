#include <bits/stdc++.h>

using namespace std;

const int N = 6;

int arr[N] = {1, 2, 3, -1, 9, 3};
int segment_tree[2 * N - 1];

void build(int v, int l, int r)
{
    if (l == r)
        segment_tree[v] = arr[l];
    else
    {
        int mid = (l + r) >> 1;

        build(v + 1, l, mid);
        build(v + ((mid - l + 1) << 1), mid + 1, r);

        segment_tree[v] = segment_tree[v + 1] + segment_tree[v + ((mid - l + 1) << 1)];
    }
}

void update(int v, int l, int r, int pos, int new_val)
{
    if (l == r)
        segment_tree[v] = new_val;
    else
    {
        int mid = (l + r) >> 1;

        if (pos <= mid)
            update(v + 1, l, mid, pos, new_val);
        else
            update(v + ((mid - l + 1) << 1), mid + 1, r, pos, new_val);

        segment_tree[v] = segment_tree[v + 1] + segment_tree[v + ((mid - l + 1) << 1)];
    }
}

int find_sum(int v, int l, int r, int x, int y)
{
    if (x > y)
        return 0;
    if (l == x && r == y)
        return segment_tree[v];

    int mid = (l + r) >> 1;

    return find_sum(v + 1, l, mid, x, min(mid, y)) + find_sum(v + ((mid - l + 1) << 1), mid + 1, r, max(mid + 1, x), y);
}

int main()
{
    build(0, 0, N - 1);
    update(0, 0, N - 1, 3, 1);
    cout << find_sum(0, 0, N - 1, 2, 4) << endl;

    return 0;
}