#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>

using namespace std;
#define mod 1000000007
#define ll long long

int arr[100009];
int dp[100009];
int n;

int solve(int idx)
{

    if (idx == n - 1)
        return 0;

    if (dp[idx] != -1)
        return dp[idx];

    int ans = solve(idx + 1) + abs(arr[idx + 1] - arr[idx]);
    if (idx + 2 < n)
        ans = min(ans, solve(idx + 2) + abs(arr[idx + 2] - arr[idx]));

    return dp[idx] = ans;
}

int main()
{

    memset(dp, -1, sizeof(dp));
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    cout << solve(0) << endl;

    return 0;
}