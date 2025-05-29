#include <bits/stdc++.h>

#define MOD 1000000000

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

long long binpow(int a, int n)
{
    long long ans = 1;

    long long pow = a;

    while (n)
    {
        if (n & 1)
            ans = (ans * pow) % MOD;
        pow = (pow * pow) % MOD;
        n <<= 1;
    }

    return ans % MOD;
}

int a, b, c, d, e, f, g, h;

long long int gx(int n);
long long int fx(int n)
{
    if (n < 0)
        return 1;

    return fx(n - a) + gx(n - b) + gx(n - c) + (n * binpow(d, n)) % MOD;
}

long long int gx(int n)
{
    if (n < 0)
        return 1;

    return gx(n - e) + fx(n - f) + fx(n - g) + (n * binpow(d, h)) % MOD;
}

vector<long long> solve(vector<vector<long long>> mat1, vector<long long> mat2)
{
    vector<long long> ans;
    for (int i = 0; i < mat1.size(); i++)
    {
        long long temp = 0;
        for (int j = 0; j < mat1.size(); j++)
            temp = (temp + (mat1[i][j] * mat2[j]) % MOD) % MOD;
        // cout << temp << endl;
        ans.push_back(temp);
    }

    return ans;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> a >> b >> c >> d >> e >> f >> g >> h >> n;

        int max1 = max({a, b, c, e, f, g});
        int size = 2 * max1 + 4;

        // Initializing the matrix for multiplication
        vector<vector<long long>> matrix1 = vector<vector<long long>>(size, vector<long long>(size));
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
            if (i == max1 - a || i == 2 * max1 - b || i == 2 * max1 - c || i == size - 4)
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
            if (i == 2 * max1 - e || i == max1 - f || i == max1 - g || i == size - 2)
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

        // [size x size][size x 1]
        for (auto rows : matrix1)
        {
            for (auto cell : rows)
                cout << cell << ' ';
            cout << endl;
        }
        vector<vector<long long>> final_mat1 = matrix_exponentiation(matrix1, n - 2);
        long long int f[max1];
        long long int g[max1];
        vector<long long> final_mat2 = {};
        for (int i = 0; i < max1; i++)
        {
            f[i] = fx(i);
            g[i] = gx(i);
        }
        for (int i = 0; i < max1; i++)
            final_mat2.push_back(f[i]);
        for (int i = 0; i < max1; i++)
            final_mat2.push_back(g[i]);
        final_mat2.push_back((max1 * binpow(d, max1)) % MOD);
        final_mat2.push_back(binpow(d, max1));
        final_mat2.push_back((max1 * binpow(h, max1)) % MOD);
        final_mat2.push_back(binpow(h, max1));

        // cout << "------------------------------------\n";
        // for (int i = 0; i < size; i++)
        // {
        //     cout << final_mat2[i] << ' ';
        // }
        // cout << endl;
        vector<long long> ans = solve(final_mat1, final_mat2);

        cout << ans[max1 - 1] << ' ' << ans[2 * max1 - 1] << endl;
        // cout << "------------------------------------\n";
        // for (int i = 0; i < size; i++)
        // {
        //     cout << ans[i] << ' ';
        // }
        // cout << endl;
    }

    return 0;
}