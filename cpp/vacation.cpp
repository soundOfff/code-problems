#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10, INF = 1e9;
int a[4][MAXN], dp[4][MAXN], n, k;
inline void init(int argc, char **argv)
{
    if (argc == 2 && !strcmp("input.txt", argv[1]))
    {
        cerr << "reading from in.txt" << endl;
        freopen(argv[1], "r", stdin);
    }
}
int main(int argc, char **argv)
{
    cin.tie(0);
    cout.tie(0);
    init(argc, argv);
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 1; j < 4; j++)
            cin >> a[j][i];
    for (int i = 0; i < 4; i++)
        dp[i][n] = 0;
    for (int day = n - 1; day >= 0; day--)
    {
        for (int prev = 0; prev < 4; prev++)
        {
            dp[prev][day] = -INF;
            for (int current = 1; current < 4; current++)
            {
                if (prev == current)
                    continue;
                dp[prev][day] = max(dp[prev][day], dp[current][day + 1] + a[current][day]);
            }
        }
    }
    cout << dp[0][0] << '\n'; //
    return 0;
}