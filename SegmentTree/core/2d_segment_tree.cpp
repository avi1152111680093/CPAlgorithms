#include <bits/stdc++.h>

using namespace std;

const int N = 4;
const int M = 4;

int segment_tree[4 * N][4 * M];

int arr[N][M] = {
    {3, 4, 1, 5},
    {7, 5, 4, 0},
    {3, 2, 9, 0},
    {3, 4, 1, 5},
};

void build_y(int vx, int lx, int rx, int vy, int ly, int ry)
{
    if (ly == ry)
    {
        if (lx == rx)
            segment_tree[vx][vy] = arr[lx][ly];
        else
            segment_tree[vx][vy] = segment_tree[2 * vx][vy] + segment_tree[2 * vx + 1][vy];
    }
    else
    {
        int mid_y = (ly + ry) >> 1;

        build_y(vx, lx, rx, 2 * vy, ly, mid_y);
        build_y(vx, lx, rx, 2 * vy + 1, mid_y + 1, ry);

        segment_tree[vx][vy] = segment_tree[vx][2 * vy] + segment_tree[vx][2 * vy + 1];
    }
}

void build_x(int vx, int lx, int rx)
{
    if (lx != rx)
    {
        int mid_x = (lx + rx) >> 1;
        build_x(2 * vx, lx, mid_x);
        build_x(2 * vx + 1, mid_x + 1, rx);
    }

    build_y(vx, lx, rx, 1, 0, M - 1);
}

int sum_y(int vx, int vy, int tly, int try_, int ly, int ry)
{
    if (ly > ry)
        return 0;
    if (tly == ly && try_ == ry)
        return segment_tree[vx][vy];

    int mid_y = (tly + try_) >> 1;

    return sum_y(vx, 2 * vy, tly, mid_y, ly, min(ry, mid_y)) + sum_y(vx, 2 * vy + 1, mid_y + 1, try_, max(ly, mid_y + 1), ry);
}

int sum_x(int vx, int tlx, int trx, int lx, int rx, int ly, int ry)
{
    if (lx > rx)
        return 0;
    if (lx == tlx && rx == trx)
        return sum_y(vx, 1, 0, M - 1, ly, ry);

    int mid = (tlx + trx) >> 1;

    return sum_x(2 * vx, tlx, mid, lx, min(rx, mid), ly, ry) + sum_x(2 * vx + 1, mid + 1, trx, max(mid + 1, lx), rx, ly, ry);
}

int main()
{
    build_x(1, 0, N - 1);

    cout << sum_x(1, 0, N - 1, 1, 3, 0, 3) << endl;
}