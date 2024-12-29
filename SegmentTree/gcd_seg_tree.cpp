#include <bits/stdc++.h>

using namespace std;

const int N = 5;

int arr[N] = {5, 3, 6, 9, 8};
int segment_tree[4 * N];

int gcd(int a, int b)
{
    int res = min(a, b);

    while (res > 1)
    {
        if (a % res == 0 && b % res == 0)
            break;
        res--;
    }
    return res;
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

        segment_tree[v] = gcd(segment_tree[2 * v], segment_tree[2 * v + 1]);
    }
}

int find_gcd(int v, int l, int r, int x, int y)
{
    if (l == x && r == y)
        return segment_tree[v];
    else
    {
        int mid = (l + r) >> 1;

        if (x > min(mid, y))
            return find_gcd(2 * v + 1, mid + 1, r, max(mid + 1, x), y);
        if (max(mid + 1, x) > y)
            return find_gcd(2 * v, l, mid, x, min(mid, y));

        return gcd(find_gcd(2 * v, l, mid, x, min(mid, y)), find_gcd(2 * v + 1, mid + 1, r, max(mid + 1, x), y));
    }
}

int main()
{
    build(1, 0, N - 1);
    cout << find_gcd(1, 0, N - 1, 2, 4) << endl;

    return 0;
}