#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fori(i, n) for (int i = 0; i < (n); ++i)

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        int ans = 0;
        vector<pair<int, int>> points;
        cin >> n;

        fori(i, n)
        {
            int a, b;
            cin >> a >> b;
            points.push_back({a, b});
        }

        fori(i, n)
        {
            fori(j, n)
            {
                if (i == j)
                    continue;
                fori(k, n)
                {
                    if (k == i || k == j)
                        continue;

                    int x1 = points[i].first, y1 = points[i].second;
                    int x2 = points[j].first, y2 = points[j].second;
                    int x3 = points[k].first, y3 = points[k].second;

                    int d12 = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
                    int d13 = (x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3);
                    int d23 = (x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3);

                    if (d12 + d13 == d23 || d12 + d23 == d13 || d13 + d23 == d12)
                    {
                        ans++;
                    }
                }
            }
        }

        cout << ans / 6 << endl;
    }
    return 0;
}

// #include <bits/stdc++.h>

// using namespace std;

// typedef long long ll;
// typedef pair<int, int> ii;
// typedef vector<int> vi;
// typedef vector<ll> vl;
// typedef vector<ii> vp;
// typedef vector<long long int> vll;
// typedef vector<char> vc;
// typedef long double ld;

// const int INF = 1e9 + 7;
// const int MOD = 1e9 + 7;
// const int MAXN = 1e6 + 3;

// #define _ % MOD
// #define __ %= MOD

// #define fori(i, n) for (int i = 0; i < (n); ++i)
// #define fora(i, a, n) for (int i = a; i <= (n); ++i)
// #define ford(i, a, n) for (int i = a; i >= (n); --i)
// #define pq(x) priority_queue<x, std::vector<x>, compare>

// #define min3(a, b, c) min(a, min(b, c))
// #define max3(a, b, c) max(a, max(b, c))
// #define min4(a, b, c, d) min(a, min(b, min(c, d)))
// #define max4(a, b, c, d) max(a, max(b, max(c, d)))

// #define pb push_back

// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n;
//         cin >> n;
//         // vector<ii> up_points;
//         // vector<ii> down_points;
//         vector<ii> points;
//         fori(i, n)
//         {
//             int x, y;
//             cin >> x >> y;
//             points.push_back({x,  y});
//             // if (y == 1)
//             // {
//             //     points.push_back({x, y});
//             // }
//             // else
//             // {
//             //     down_points.push_back({x, y});
//             // }
//         }
//         int ans = 0;
//         for (auto x : up_points)
//         {
//             int x1 = x.first;
//             int y1 = x.second;
//             fori(y, int(poinst.size()))
//             {
//                 int x2 = down_points[y].first;
//                 int y2 = down_points[y].second;
//                 fori(z, int(down_points.size()))
//                 {
//                     if (y == z)
//                         continue;
//                     int x3 = down_points[z].first;
//                     int y3 = down_points[z].second;
//                     int d12 = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
//                     int d13 = (x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3);
//                     int d23 = (x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3);

//                     if (d12 + d13 == d23 || d12 + d23 == d13 || d13 + d23 == d12)
//                     {
//                         ans++;
//                     }
//                 }
//             }
//         }
//         cout << (ans != 0 ? ans-2 : ans) << endl;
//     }
// }