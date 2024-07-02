#include <bits/stdc++.h>
#include <cmath>

#define ll long long

using namespace std;

ll n, w;
const ll MAX_N = 1e5 + 10;
ll W[MAX_N];
ll V[MAX_N];
ll dp[105][MAX_N];

void init()
{
    cin >> n >> w;
    for (ll i = 1; i <= n; i++)
        cin >> W[i] >> V[i];
    memset(dp, -1, sizeof(dp));
}

ll solve(ll w, ll n)
{
    if (n == 0 || w <= 0)
        return 0;

    if (dp[n][w] != -1)
        return dp[n][w];

    ll a1 = (w - W[n] >= 0) ? (V[n] + solve(w - W[n], n - 1)) : INT_MIN;
    ll a2 = solve(w, n - 1);

    return dp[n][w] = max(a1, a2);
}

int main()
{
    init();
    cout << solve(w, n) << '\n';
}