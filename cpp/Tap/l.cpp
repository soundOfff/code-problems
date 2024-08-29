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
const int MAXN = 2 * 1e5 + 3;

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

ll N, M;
vector<vl> adj(MAXN);
vector<bool> visited(MAXN, false);
vl colors(MAXN, -1);

bool isBipartite(int s)
{
    for (auto u : adj[s])
    {
        if (visited[u] == false)
        {
            visited[u] = true;
            colors[u] = colors[s] == 0 ? 1 : 0;
            if (!isBipartite(u))
                return false;
        }
        else if (colors[u] == colors[s])
            return false;
    }
    return true;
}

int main()
{
    cin >> N >> M;
    vl origin;

    fori(i, M)
    {
        ll ai, bi;
        cin >> ai >> bi;
        adj[ai].pb(bi);
        adj[bi].pb(ai);
        origin.pb(ai);
    };

    visited[1] = true;
    colors[1] = 0;

    bool flag = isBipartite(1);

    if (flag)
    {
        cout << "YES" << endl;
        fori(k, M)
        {
            if (colors[origin[k]] == 0)
            {
                cout << "1";
            }
            else
            {
                cout << "0";
            }
        }
        cout << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}