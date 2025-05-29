#include <bits/stdc++.h>

#define MOD 1000000007

typedef long long LL;

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
            for (int k = 0; k < size; k++)
                temp = (temp + matrix1[i][k] * matrix2[k][j]) % MOD;

            ans[i][j] = temp;
        }
    }

    return ans;
}

void print_mat(vector<vector<LL>> mat, string name)
{
    cout << name << endl;
    for (auto row : mat)
    {
        for (LL i : row)
            cout << i << ' ';
        cout << endl;
    }
    cout << "------------------------------" << endl;
}

vector<vector<LL>> mat_expo(vector<vector<LL>> matrix, int n)
{
    vector<vector<LL>> ans = {{1, 0}, {0, 1}};
    vector<vector<LL>> pow = matrix;

    while (n)
    {
        if (n & 1)
        {
            ans = mult_matrix(ans, pow);
        }
        pow = mult_matrix(pow, pow);

        // print_mat(ans, "ans");
        // print_mat(ans, "pow");
        n >>= 1;
    }

    return ans;
}

LL solve(vector<vector<LL>> mat1, vector<LL> mat2)
{
    return ((mat1[1][0] * mat2[0]) % MOD + (mat1[1][1] * mat2[1]) % MOD) % MOD;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int a, b, n;
        cin >> a >> b >> n;

        if (n == 0)
        {
            cout << a << endl;
            continue;
        }
        if (n == 1)
        {
            cout << b << endl;
            continue;
        }

        vector<vector<LL>> mat1 = {{0, 1}, {1, 1}};
        vector<LL> mat2 = {a, b};

        vector<vector<LL>> mat = mat_expo(mat1, n - 1);

        cout << solve(mat, mat2) << endl;
    }

    return 0;
}