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

int main()
{
    int n;
    cin >> n;
    vi a(n + 1);
    int max_val = -1, min_val = INT_MAX, mid_val = -1;
    int max_i = -1, min_i = -1, mid_i = -1;
    fora(i, 1, n) cin >> a[i];

    fora(i, 1, n)
    {
        if (a[i] > max_val)
        {
            max_val = a[i];
            max_i = i;
        }
        if (a[i] < min_val)
        {
            min_val = a[i];
            min_i = i;
        }
    }

    fora(i, 1, n)
    {
        if (a[i] > min_val && a[i] < max_val)
        {
            mid_val = a[i];
            mid_i = i;
            break;
        }
    }

    if (max_val == -1 || min_val == INT_MAX || mid_val == -1)
    {
        cout << -1 << " " << -1 << " " << -1 << endl;
    }
    else
    {
        cout << min_i << " " << mid_i << " " << max_i << endl;
    }

    return 0;
}