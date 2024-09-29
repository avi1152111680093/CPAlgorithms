#include <bits/stdc++.h>

using namespace std;

const int MN = 1e5;
int sparse_table[MN][17];

int main() {
    int n = 10;
    int m = log2(n)+1;
    int arr[10] = {2, 4, 1, 9, -3, 1, 6, 0, -9, 4};

    // Logic for creating sparse table
    for (int i=0; i<n; i++) sparse_table[i][0] = arr[i];
    for (int j=1; j<m; j++) for (int i=0; i<n-(1<<(j-1)); i++) sparse_table[i][j] = min(sparse_table[i][j-1], sparse_table[i+(1<<(j-1))][j-1]);
    // -------------------------------



    return 0;
}