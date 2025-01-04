#include <bits/stdc++.h>

using namespace std;

// {8, 11, 11, 13, 14}
// {0, 2, 6, 7, 19},
// {2, 13, 18, 19, 20},
// {3, 4, 6, 6, 7},

const int N = 5;
vector<vector<int>> arr = {
    {3, 4, 6, 6, 7},
    {2, 13, 18, 19, 20},
    {0, 2, 6, 7, 19},
    {8, 11, 11, 13, 14}};

// Tuple contains, (aux_value, org_idx, aux_idx)
vector<vector<tuple<int, int, int>>> aux_arr(arr.size());

void build()
{
    for (int i = 0; i < arr[0].size(); i++)
        aux_arr[0].push_back({arr[0][i], i, -1});

    for (int i = 1; i < arr.size(); i++)
    {
        // Merge, arr[i] with odd places of aux_arr[i-1]
        vector<int> temp_vec, new_vec;
        for (int t = 1; t < aux_arr[i - 1].size(); t += 2)
            temp_vec.push_back(get<0>(aux_arr[i - 1][t]));

        merge(arr[i].begin(), arr[i].end(), temp_vec.begin(), temp_vec.end(), back_inserter(new_vec));

        transform(new_vec.begin(), new_vec.end(), back_inserter(aux_arr[i]), [](int num)
                  { return make_tuple(num, -1, -1); });
    }

    for (int i = aux_arr.size() - 1; i >= 1; i--)
    {
        // arr[i]
        for (int j = 0; j < aux_arr[i].size(); j++)
        {
            vector<int>::iterator pos1 = lower_bound(arr[i].begin(), arr[i].end(), get<0>(aux_arr[i][j]));
            vector<int> temp_vec;
            transform(aux_arr[i - 1].begin(), aux_arr[i - 1].end(), back_inserter(temp_vec), [](tuple<int, int, int> tup)
                      { return get<0>(tup); });

            vector<int>::iterator pos2 = lower_bound(temp_vec.begin(), temp_vec.end(), get<0>(aux_arr[i][j]));

            int pos1_i = pos1 - arr[i].begin();
            int pos2_i = pos2 - temp_vec.begin();

            aux_arr[i][j] = {get<0>(aux_arr[i][j]), pos1_i, pos2_i};
        }
    }

    // for (int i = aux_arr.size() - 1; i >= 0; i--)
    // {
    //     for (int j = 0; j < aux_arr[i].size(); j++)
    //     {
    //         printf("%d[%d,%d] ", get<0>(aux_arr[i][j]), get<1>(aux_arr[i][j]), get<2>(aux_arr[i][j]));
    //     }
    //     cout << endl;
    // }
}

vector<int> find_lower_bounds(int val)
{
    vector<int> ans;

    int n = aux_arr.size();

    vector<int> temp_vec;
    transform(aux_arr[n - 1].begin(), aux_arr[n - 1].end(), back_inserter(temp_vec), [](tuple<int, int, int> tup)
              { return get<0>(tup); });

    vector<int>::iterator pos = lower_bound(temp_vec.begin(), temp_vec.end(), val);
    int pos_i = pos - temp_vec.begin();

    int arr_idx = get<1>(aux_arr[n - 1][pos_i]);
    int aux_idx = get<2>(aux_arr[n - 1][pos_i]);

    ans.push_back(arr_idx);

    for (int i = aux_arr.size() - 2; i >= 0; i--)
    {
        if (aux_idx >= aux_arr[i].size())
        {
            ans.push_back(-1);
            continue;
        }

        if (get<0>(aux_arr[i][aux_idx - 1]) >= val)
        {
            arr_idx = get<1>(aux_arr[i][aux_idx - 1]);
            aux_idx = get<2>(aux_arr[i][aux_idx - 1]);
        }
        else
        {
            arr_idx = get<1>(aux_arr[i][aux_idx]);
            aux_idx = get<2>(aux_arr[i][aux_idx]);
        }

        ans.push_back(arr_idx);
    }

    return ans;
}

int main()
{
    build();

    vector<int> ans = find_lower_bounds(5);

    for (int i : ans)
        cout << i << ' ';
    cout << endl;

    return 0;
}