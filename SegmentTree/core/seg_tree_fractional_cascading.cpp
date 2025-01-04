#include <bits/stdc++.h>

using namespace std;

const int N = 8;
int arr[N] = {1, 2, 0, -2, -1, 9, 4, 6};

vector<tuple<int, int, int>> segment_tree[4 * N];

void build(int v, int l, int r)
{
    if (l == r)
        segment_tree[v] = {{arr[l], l, r}};
    else
    {
        int mid = (l + r) >> 1;

        build(2 * v, l, mid);
        build(2 * v + 1, l, mid);

        vector<int> temp1;
        vector<int> temp2;

        transform(segment_tree[2 * v].begin(), segment_tree[2 * v].end(), back_inserter(temp1), [](tuple<int, int, int> tup)
                  { return get<0>(tup); });
        transform(segment_tree[2 * v + 1].begin(), segment_tree[2 * v + 1].end(), back_inserter(temp2), [](tuple<int, int, int> tup)
                  { return get<0>(tup); });

        vector<int> temp;

        merge(temp1.begin(), temp1.end(), temp2.begin(), temp2.end(), back_inserter(temp));

        transform(temp.begin(), temp.end(), back_inserter(segment_tree[v]), [temp1, temp2](int val)
                  { 
                    int pos1 = lower_bound(temp1.begin(), temp1.end(), val) - temp1.begin();
                    int pos2 = lower_bound(temp2.begin(), temp2.end(), val)- temp2.begin();

                    return make_tuple(val, pos1, pos2); });
    }
}

int find_lower_bound(int v, int l, int r, int x, int y, int val)
{
}

int main()
{
}