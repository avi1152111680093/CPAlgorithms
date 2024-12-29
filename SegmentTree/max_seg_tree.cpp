// This code finds maximum within a range also the number of times that maximum is achieved

#include <bits/stdc++.h>

using namespace std;

const int N = 4;

int arr[N] = {1, 2, 3, -2};
pair<int, int> segment_tree[4 * N];

pair<int, int> combine(pair<int, int> a, pair<int, int> b)
{
    if (a.first > b.first)
        return a;
    if (b.first > a.first)
        return b;
    return {a.first, a.second + b.second};
}

void build(int v, int l, int r)
{
    if (l == r)
        segment_tree[l] = {arr[l], 1};
    else
    {
        int mid = (l + r) >> 1;

        build(2 * v, l, mid);
        build(2 * v + 1, mid + 1, r);

        segment_tree[v] = combine(segment_tree[2 * v], segment_tree[2 * v + 1]);
    }
}

pair<int, int> query(int v, int l, int r, int x, int y)
{
    if (x > y)
        return {INT_MIN, 0};
    if (l == x && r == y)
        return segment_tree[v];
    int mid = (l + r) >> 1;

    return combine(query(2 * v, l, mid, x, min(mid, y)), query(2 * v + 1, mid + 1, r, max(x, mid + 1), y));
}

void update(int v, int l, int r, int pos, int new_val)
{
    if (l == r)
        segment_tree[v] = {arr[l], 1};
    else
    {
        int mid = (l + r) >> 1;

        if (pos <= mid)
            update(2 * v, l, mid, pos, new_val);
        else
            update(2 * v, mid + 1, r, pos, new_val);

        segment_tree[v] = combine(segment_tree[2 * v], segment_tree[2 * v + 1]);
    }
}

int main()
{

    return 0;
}