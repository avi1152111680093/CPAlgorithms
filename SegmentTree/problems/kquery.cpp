// Getting TLE, but the solution is right

#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; i++)

using namespace std;

int arr[30001];
vector<int> segment_tree[4 * 30001];

void build(int v, int l, int r)
{
    if (l == r)
        segment_tree[v] = vector<int>(1, arr[l]);
    else
    {
        int mid = (l + r) >> 1;

        build(2 * v, l, mid);
        build(2 * v + 1, mid + 1, r);

        merge(segment_tree[2 * v].begin(), segment_tree[2 * v].end(), segment_tree[2 * v + 1].begin(), segment_tree[2 * v + 1].end(), back_inserter(segment_tree[v]));
    }
}

int query(int v, int l, int r, int x, int y, int val)
{
    if (y < l || x > r)
        return 0;
    if (x > y)
        return 0;
    if (l >= x && r <= y)
    {
        // vector<int>::iterator pos_itr = upper_bound(segment_tree[v].begin(), segment_tree[v].end(), val);
        // if (pos_itr == segment_tree[v].end())
        //     return 0;
        return segment_tree[v].end() - upper_bound(segment_tree[v].begin(), segment_tree[v].end(), val);
    }

    int mid = (l + r) >> 1;

    return query(2 * v, l, mid, x, y, val) + query(2 * v + 1, mid + 1, r, x, y, val);
}

int main()
{
    int n, q;
    cin >> n;

    FOR(i, n) { cin >> arr[i]; }

    cin >> q;

    int queries[q][3];

    FOR(i, q)
    {
        FOR(j, 3) { cin >> queries[i][j]; }
    }

    build(1, 0, n - 1);

    FOR(i, q) { cout << query(1, 0, n - 1, queries[i][0] - 1, queries[i][1] - 1, queries[i][2]) << endl; }

    return 0;
}