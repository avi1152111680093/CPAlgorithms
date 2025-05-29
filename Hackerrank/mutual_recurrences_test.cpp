#include <bits/stdc++.h>

typedef long long LL;
// typedef vector<int> vi;
// typedef vector<long long> vll;
// typedef vector<vector<int>> vvi;
// typedef vector<vector<long long>> vvll;

using namespace std;

vector<vector<long long>> mult_matrix(vector<vector<long long>> matrix1, vector<vector<long long>> matrix2)
{
    int size = matrix1.size();
    vector<vector<long long>> ans = vector<vector<long long>>(size, vector<long long>(size));

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            long long int temp = 0;
            // Taking ith row from the matrix1 and the jth comlumn from the matrix2, and do, scalar product of the two matrices
            for (int k = 0; k < size; k++)
                temp += (matrix1[i][k] * matrix2[k][j]);

            ans[i][j] = temp;
        }
    }

    return ans;
}

vector<vector<long long>> matrix_exponentiation(vector<vector<long long>> matrix, long long n)
{
    int size = matrix.size();
    vector<vector<long long>> ans = vector<vector<long long>>(size, vector<long long>(size, 0));
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (i == j)
                ans[i][j] = 1;

    vector<vector<long long>> pow = matrix;
    while (n)
    {
        if (n & 1)
            ans = mult_matrix(ans, pow);
        pow = mult_matrix(pow, pow);
        n >>= 1;
    }

    return ans;
}

int main()
{
    // vector<vector<long long>> matrix1 = {{1, 2, 3}, {-1, 1, 2}, {4, 1, -3}};

    // auto matrix = matrix_exponentiation(matrix1, 100);

    // for (auto rows : matrix)
    // {
    //     for (auto cell : rows)
    //         cout << cell << '\t';
    //     cout << endl;
    // }
    // int max1 = max({a, b, c, e, f, g});
    int a = 1, b = 3, c = 4, d = 5, e = 2, f = 1, g = 3, h = 6;
    int max1 = 4;
    int size = 2 * max1 + 4;
    vector<vector<long long>> matrix1 = vector<vector<long long>>(size, vector<long long>(size, 0));
    for (int i = 0; i <= max1 - 2; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i + 1 == j)
                matrix1[i][j] = 1;
            else
                matrix1[i][j] = 0;
        }
    }
    for (int i = 0; i < size; i++)
    {
        if (i == max1 - a || i == 2 * max1 - b || i == 2 * max1 - c)
            matrix1[max1 - 1][i] = 1;
        else
            matrix1[max1 - 1][i] = 0;
    }
    for (int i = max1; i <= 2 * max1 - 2; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i + 1 == j)
                matrix1[i][j] = 1;
            else
                matrix1[i][j] = 0;
        }
    }
    for (int i = 0; i < size; i++)
    {
        if (i == 2 * max1 - e || i == max1 - f || i == max1 - g)
            matrix1[2 * max1 - 1][i] = 1;
        else
            matrix1[2 * max1 - 1][i] = 0;
    }
    for (int i = 0; i < size; i++)
    {
        if (i == 2 * max1 + 3 || i == 2 * max1 + 2)
            matrix1[2 * max1][i] = d;
        else
            matrix1[2 * max1][i] = 0;
    }
    for (int i = 0; i < size; i++)
    {
        if (i == 2 * max1 + 3)
            matrix1[2 * max1 + 1][i] = d;
        else
            matrix1[2 * max1 + 1][i] = 0;
    }
    for (int i = 0; i < size; i++)
    {
        if (i == 2 * max1 + 3 || i == 2 * max1 + 2)
            matrix1[2 * max1 + 2][i] = h;
        else
            matrix1[2 * max1 + 2][i] = 0;
    }
    for (int i = 0; i < size; i++)
    {
        if (i == 2 * max1 + 3)
            matrix1[2 * max1 + 3][i] = h;
        else
            matrix1[2 * max1 + 3][i] = 0;
    }
    for (auto rows : matrix1)
    {
        for (auto cell : rows)
            cout << cell << ' ';
        cout << endl;
    }

    return 0;
}