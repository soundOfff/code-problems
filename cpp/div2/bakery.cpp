#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
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

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define fbo find_by_order
#define ook order_of_key

ll n, b, a;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

bool pos(ll k) {
    bool flag = true;
    ford(i, k, 1) {
        if ((b-i+1) < a) {
            flag = false;
            break;
        }
    }
    return flag;
}

ll binary_search()
{
    ll low = 0, high = min(n, b);
    while (low < high)
    {
        ll mid = (low + high + 1) / 2;
        if (pos(mid))
        {
            low = mid;
        }
        else
        {
            high = mid - 1;
        }
    }
    return high;
}

void solve() {
    ll ideal_k = binary_search();
    ll acum = 0;
    // cout << "ideal k: " << ideal_k << '\n';
    fora(i, 1, ideal_k) {
        acum += b - i + 1;
    }
    acum += (n-ideal_k)*a;

    cout << acum << '\n';
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> a >> b;
        solve();
    }
}