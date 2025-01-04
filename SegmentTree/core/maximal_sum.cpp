#include <bits/stdc++.h>

using namespace std;

const int N = 8;

int arr[N] = {1, 2, 0, -2, -1, 9, 4, 6};
// Each vertex of the segment tree will be storing the following
// tuple will be storing
// 0. Sum of the segment
// 1. Maximal prefix sum
// 2. Maximal suffix sum
// 3. Maximal subsegment inside of the segment
tuple<int, int, int, int> segment_tree[4 * N];

tuple<int, int, int, int> combine(tuple<int, int, int, int> left, tuple<int, int, int, int> right)
{
    int left_sum = get<0>(left);
    int right_sum = get<0>(right);
    int left_prefix_maximal_sum = get<1>(left);
    int left_suffix_maximal_sum = get<2>(left);
    int right_prefix_maximal_sum = get<1>(right);
    int right_suffix_maximal_sum = get<2>(right);
    int left_maximal_sum = get<3>(left);
    int right_maximal_sum = get<3>(right);

    int v1 = left_sum + right_sum;
    int v2 = max(left_prefix_maximal_sum, left_sum + right_prefix_maximal_sum);
    int v3 = max(right_suffix_maximal_sum, right_sum + left_suffix_maximal_sum);
    int v4 = max(left_maximal_sum, right_maximal_sum);
    v4 = max(v4, left_suffix_maximal_sum + right_prefix_maximal_sum);
    return {v1, v2, v3, v4};
}

void build(int v, int l, int r)
{
    if (l == r)
        segment_tree[v] = {arr[l], arr[l], arr[l], arr[l]};
    else
    {
        int mid = (l + r) >> 1;

        build(2 * v, l, mid);
        build(2 * v + 1, mid + 1, r);

        segment_tree[v] = combine(segment_tree[2 * v], segment_tree[2 * v + 1]);
    }
}

tuple<int, int, int, int> find_maximal(int v, int l, int r, int x, int y)
{
    if (x > y)
        return {0, 0, 0, 0};

    if (l == x && r == y)
        return segment_tree[v];

    int mid = (l + r) >> 1;

    auto left_segment = find_maximal(2 * v, l, mid, x, min(mid, y));
    auto right_segment = find_maximal(2 * v + 1, mid + 1, r, max(x, mid + 1), y);

    return combine(left_segment, right_segment);
}

int main()
{
    build(1, 0, N - 1);

    cout << get<3>(find_maximal(1, 0, N - 1, 3, 5)) << endl;

    // for (int i = 1; i <= 7; i++)
    // {
    //     cout << i << endl;
    //     cout << "Max prefix sum: " << get<1>(segment_tree[i]) << endl;
    //     cout << "Max suffix sum: " << get<2>(segment_tree[i]) << endl;
    //     cout << "Maximul sum: " << get<3>(segment_tree[i]) << endl;
    //     cout << "---------------------------------------------" << endl;
    // }

    return 0;
}