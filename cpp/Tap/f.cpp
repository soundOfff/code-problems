// Training camp problem - F. Hongcow Builds A Nation
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
int N,M,K;
vi sp(1005);
vi special_nodes(1005, 0); // Amount of nodes grouped by a special node
vi special_edges(1005, 0); // Real amount of edges grouped by a special node
vector<bool> visited(1005, false);
vector<vi> adj(1e5 + 5); // 100000


void dfs(int s, int special_node) {
    if (visited[s]) return;
    visited[s] = true;
    special_nodes[special_node] += 1;
    for (auto u: adj[s]) {
        special_edges[special_node] += 1;
        dfs(u, special_node);
    }
} 


int main()
{
    cin >> N >> M >> K;
    fori(i, K) {
        cin >> sp[i];
    }
    fori(i, M) {
        int ai, bi;
        cin >> ai >> bi;
        adj[ai].pb(bi);
        adj[bi].pb(ai);
    }

    int ans = 0;
    fori(kk, int(sp.size())) {
        if (sp[kk] > 0) {
        dfs(sp[kk], sp[kk]);
        }
    }

    int total_special_nodes = 0;
    int edges_in_specials = 0;

    auto max_group = max_element(special_nodes.begin(), special_nodes.end());

    fori(j, int(special_nodes.size())) {
        total_special_nodes += special_nodes[j];
        if (special_nodes[j] > 0) {
            edges_in_specials += (special_nodes[j] * (special_nodes[j] - 1) / 2) - (special_edges[j] / 2); // total amount of edges - real amount of edges
        }
    }

    int edges_not_specials = M - edges_in_specials;

    // N real amount of nodes
    int unassigned_nodes = N - total_special_nodes;

    ans = edges_in_specials + (int(*max_group) * unassigned_nodes) + ((unassigned_nodes * (unassigned_nodes - 1) / 2) - edges_not_specials) + 1;
 
    cout << (ans >= 0 ? ans : 0) << endl;
}