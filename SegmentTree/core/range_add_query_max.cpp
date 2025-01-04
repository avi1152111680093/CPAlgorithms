#include <bits/stdc++.h>

using namespace std;

const int N = 6;
int arr[N] = {5, 2, 4, 0, 1, -3};

int segment_tree[4 * N];
int addends[4 * N];

void push_node(int v)
{
    segment_tree[2 * v] += addends[v];
    segment_tree[2 * v + 1] += addends[v];

    addends[2 * v] += addends[v];
    addends[2 * v + 1] += addends[v];

    addends[v] = 0;
}

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

void update(int v, int l, int r, int x, int y, int val)
{
    if (x > y)
        return;
    if (l == x && r == y)
    {
        addends[v] += val;
        segment_tree[v] += val;
    }
    else
    {
        push_node(v);

        int mid = (l + r) >> 1;

        update(2 * v, l, mid, x, min(y, mid), val);
        update(2 * v + 1, mid + 1, r, max(mid + 1, x), y, val);

        segment_tree[v] = max(segment_tree[2 * v], segment_tree[2 * v + 1]);
    }
}

int query(int v, int l, int r, int x, int y)
{
    if (x > y)
        return INT_MIN;
    if (l == x && r == y)
        return segment_tree[v];

    int mid = (l + r) >> 1;

    push_node(v);

    return max(query(2 * v, l, mid, x, min(mid, y)), query(2 * v + 1, mid + 1, r, max(x, mid + 1), y));
}

int main()
{
    build(1, 0, N - 1);
    update(1, 0, N - 1, 2, 4, 4);

    cout << query(1, 0, N - 1, 0, 2) << endl;

    return 0;
}