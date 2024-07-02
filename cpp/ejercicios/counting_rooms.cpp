#include <bits/stdc++.h>
using namespace std;
int ROWS, COLS;
vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void dfs(int row, int col, vector<string> &grid)
{
    grid[row][col] = '#';
    for (auto &dir : directions)
    {
        int r = row + dir[0];
        int c = col + dir[1];
        if (r < 0 || c < 0 || r >= ROWS || c >= COLS || grid[row][col] == '#')
            continue;
        dfs(r, c, grid);
    }
}

int solve(vector<string> &grid)
{
    int ans = 0;
    for (int r = 0; r < ROWS; r++)
    {
        for (int c = 0; c < COLS; c++)
        {
            if (grid[r][c] == '.')
            {
                ans++;
                dfs(r, c, grid);
            }
        }
    }
    return ans;
}
int main()
{
    cin >> ROWS >> COLS;
    vector<string> grid(ROWS);
    for (int i = 0; i < ROWS; i++)
        cin >> grid[i];
    int rooms = solve(grid);
    cout << rooms << endl;
}