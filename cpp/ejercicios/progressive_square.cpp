#include <bits/stdc++.h>

#define ll long long

using namespace std;

vector<vector<int>> fill_matrix(vector<vector<int>> m, ll size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cin >> m[i][j];
        }
    }
    return m;
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    int m = 0;
    for (int i = 0; i < t; i++)
    {
        vector<vector<int>> matrix;
        int n, c, d;
        cin >> n >> c >> d;
        fill_matrix(matrix, n);
    }
}