#include <bits/stdc++.h>

using namespace std;

const int N = 8;

int arr[N] = {1, 2, 0, -2, -1, 9, 4, 6};

// -2 0 1 2
// -1 4 6 9

multiset<int> segment_tree[4 * N];

void build(int v, int l, int r)
{
    if (l == r)
        segment_tree[v].insert(arr[l]);
    else
    {
        int mid = (l + r) >> 1;

        build(2 * v, l, mid);
        build(2 * v + 1, mid + 1, r);

        multiset<int> temp;

        temp.insert(segment_tree[2 * v].begin(), segment_tree[2 * v].end());
        temp.insert(segment_tree[2 * v + 1].begin(), segment_tree[2 * v + 1].end());

        segment_tree[v] = temp;
    }
}

void update(int v, int l, int r, int idx, int val)
{
    segment_tree[v].erase(arr[idx]);
    segment_tree[v].insert(val);

    if (l == r)
        arr[idx] = val;
    else
    {
        int mid = (l + r) >> 1;

        if (idx <= mid)
            update(2 * v, l, mid, idx, val);
        else
            update(2 * v + 1, mid + 1, r, idx, val);
    }
}

int query(int v, int l, int r, int x, int y, int val)
{
    if (x > y)
        return INT_MAX;
    if (l == x && r == y)
    {
        multiset<int>::iterator pos = lower_bound(segment_tree[v].begin(), segment_tree[v].end(), val);
        if (pos != segment_tree[v].end())
            return *pos;
        return INT_MAX;
    }
    int mid = (l + r) >> 1;

    return min(query(2 * v, l, mid, x, min(mid, y), val), query(2 * v + 1, mid + 1, r, max(mid + 1, x), y, val));
}

int main()
{
    build(1, 0, N - 1);
    update(1, 0, N - 1, 3, 4);

    cout << query(1, 0, N - 1, 2, 5, 3) << endl;

    return 0;
}