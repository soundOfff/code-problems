#include <bits/stdc++.h>
#include <cmath>

#define ll long long

using namespace std;

int n;
const ll MAX_N = 1e5 + 10;
int h[MAX_N];
int dp[MAX_N];

void init()
{
    cin >> n;
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
    int a = solve(i + 1) + abs(h[i] - h[i + 1]);
    if (i + 2 < n)
    {
        a = min(a, solve(i + 2) + abs(h[i] - h[i + 2]));
    }
    dp[i] = a;
    return a;
}

int main()
{
    init();
    cout << solve(0) << '\n';
}
