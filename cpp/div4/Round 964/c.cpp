#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pll> vp;
typedef vector<char> vc;
typedef long double ld;

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 3;

#define each(it, s) for (auto it = s.begin(); it != s.end(); ++it)
#define sortAsc(v) sort(v.begin(), v.end())
#define sortDesc(v) sort(v.begin(), v.end(), greater<>())
#define fill(a, v) memset(a, v, sizeof(a))

#define fori(i, n) for (int i = 0; i < (n); ++i)
#define fora(i, a, n) for (int i = a; i <= (n); ++i)
#define ford(i, a, n) for (int i = a; i >= (n); --i)

#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

#define fi first
#define se second
#define mp make_pair
#define pb push_back

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, s, m;
        bool flag = false;
        cin >> n >> s >> m;
        vector<pll> intervals;
        fori(i, n)
        {
            ll l, r;
            cin >> l >> r;
            intervals.pb({l, r});
        }

        sort(intervals.begin(), intervals.end());

        if (intervals[0].first >= s)
        {
            flag = true;
        }
        fora(i, 1, n - 1)
        {
            if (abs(intervals[i].first - intervals[i - 1].second) >= s)
            {
                flag = true;
            }
        }
        if (abs(intervals[n - 1].second - m) >= s)
        {
            flag = true;
        }

        cout << (flag ? "YES" : "NO") << endl;
    }
    return 0;
}
