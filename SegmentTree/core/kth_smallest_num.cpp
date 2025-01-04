#include <bits/stdc++.h>

using namespace std;

const int N = 8;

int arr[N] = {1, 2, 0, -2, -1, 9, 4, 6};

struct Vertex
{
    Vertex *l, *r;
    int sum;

    Vertex(int val) : l(nullptr), r(nullptr), sum(val) {}
    Vertex(Vertex *l, Vertex *r) : l(l), r(r), sum(0)
    {
        if (l)
            sum += l->sum;
        if (r)
            sum += r->sum;
    }
};

Vertex *build(int l, int r)
{
    if (l == r)
        return new Vertex(0);

    int mid = (l + r) >> 1;

    return new Vertex(build(arr, l, mid), build(arr, mid + 1, r));
}

int get_sum(Vertex *v, int l, int r, int x, int y)
{
    if (x > y)
        return 0;
    if (l == x && r == y)
        return v->sum;

    int mid = (l + r) >> 1;

    return get_sum(v->l, l, mid, x, min(mid, y)) + get_sum(v->r, mid + 1, r, max(mid + 1, x), y);
}

Vertex *update(Vertex *v, int l, int r, int idx)
{
    if (l == r)
        return new Vertex(v->sum + 1);

    int mid = (l + r) >> 1;

    if (idx <= mid)
        return new Vertex(update(v->l, l, mid, idx), v->r);

    return new Vertex(v->l, update(v->r, mid + 1, r, idx));
}

int find_kth(Vertex *vl, Vertex *vr, int tl, int tr, int k)
{
    if (tl == tr)
        return tl;

    int mid = (tl + tr) >> 1;
    // int left_count = vr->
}

int main()
{
    vector<int> vec(arr, arr + N);
    int max_val = *max_element(vec.begin(), vec.end());

    int l = 0;
    int r = max_val + 1;

    vector<Vertex *> roots;
    roots.push_back(build(l, r));
    for (int i = 0; i < vec.size(); i++)
        roots.push_back(update(roots.back(), l, r, vec[i]));

    return 0;
}