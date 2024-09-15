#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ii> vp;
typedef vector<long long int> vll;
typedef vector<char> vc;
typedef long double ld;

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int MAXN = 200000 + 5;

#define _ % MOD
#define __ %= MOD

#define fori(i, n) for (int i = 0; i < (n); ++i)
#define fora(i, a, n) for (int i = a; i <= (n); ++i)
#define ford(i, a, n) for (int i = a; i >= (n); --i)
#define pq(x) priority_queue<x, std::vector<x>, compare>

#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define min4(a, b, c, d) min(a, min(b, min(c, d)))
#define max4(a, b, c, d) max(a, max(b, max(c, d)))

#define pb push_back

bool visited[MAXN];

void dfs(int s, int curr, vector<int> &ans, vector<vector<pair<int, int>>> &adj)
{
    if (visited[s])
        return;
    visited[s] = true;

    for (auto u : adj[s])
    {
        if (u.second == 0)
        {
            ans[curr]++;
        }
        dfs(u.first, curr, ans, adj);
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        memset(visited, false, sizeof(visited));
        int n;
        cin >> n;
        vi p(n + 1);
        vi ans(n + 1, 0);
        vector<vector<pair<int, int>>> adj(n + 1);

        string colors;

        fora(i, 1, n) cin >> p[i];

        fora(i, 1, n)
        {
            char color;
            cin >> color;
            adj[p[i]].push_back({p[p[i]], color - '0'});
        }

        fora(i, 1, n)
        {
            dfs(i, i, ans, adj);
            memset(visited, false, sizeof(visited));
        }

        fora(i, 1, n)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}