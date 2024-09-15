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

typedef set<int>::iterator sit;
typedef map<int, int>::iterator mit;
typedef vector<int>::iterator vit;
typedef vector<long long int>::iterator vllit;

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 3;

#define _ % MOD
#define __ %= MOD

#define each(it, s) for (vit it = s.begin(); it != s.end(); ++it)
#define sortAsc(v) sort(v.begin(), v.end())
#define sortDesc(v) sort(v.begin(), v.end(), greater<auto>())
#define fill(a, v) memset(a, v, sizeof(a))

#define fori(i, n) for (int i = 0; i < (n); ++i)
#define fora(i, a, n) for (int i = a; i <= (n); ++i)
#define ford(i, a, n) for (int i = a; i >= (n); --i)
#define pq(x) priority_queue<x, std::vector<x>, compare>

#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define min4(a, b, c, d) min(a, min(b, min(c, d)))
#define max4(a, b, c, d) max(a, max(b, max(c, d)))

#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define fbo find_by_order
#define ook order_of_key

vector<pair<int, int>> adj[10005];
bool visited[105];

void dfs(int color, int root)
{
    if (visited[root])
        return;
    visited[root] = true;
    for (auto u : adj[root])
    {
        if (u.second == color && !visited[u.first])
        {
            dfs(color, u.first);
        }
    }
}

int N, M;

int main()
{
    cin >> N >> M;

    fori(j, M)
    {
        int ai, bi, ci;
        cin >> ai >> bi >> ci;
        adj[ai].pb({bi, ci});
        adj[bi].pb({ai, ci});
    }
    memset(visited, false, sizeof(visited));
    int q;
    cin >> q;

    fori(j, q)
    {
        int q1, q2;
        int ans = 0;
        cin >> q1 >> q2;
        fora(color, 1, 100)
        {
            dfs(color, q1);
            if (visited[q2])
            {
                ans++;
            }
            memset(visited, false, sizeof(visited));
        }
        cout << ans << endl;
    }
}