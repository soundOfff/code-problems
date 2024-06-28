#include <bits/stdc++.h>
#include <cmath>

#define ll long long

using namespace std;

int n, k;
const ll MAX_N = 1e5 + 10;
int h[MAX_N];
int dp[MAX_N];

void init()
{
    cin >> n >> k;
    for (ll i = 0; i < n; ++i)
        cin >> h[i];
    memset(dp, -1, sizeof(dp));
}

int solve(int i)
{
    if (i == n - 1)
    {
        return 0;
    }
    if (dp[i] != -1)
    {
        return dp[i];
    }
    int min_solve = INT_MAX;
    for (int j = 1; j <= k; j++)
    {
        if (i + j >= n)
            break;
        min_solve = min(min_solve, solve(i + j) + abs(h[i] - h[i + j]));
    }
    dp[i] = min_solve;
    return min_solve;
}

int main()
{
    init();
    cout << solve(0) << '\n';
}
