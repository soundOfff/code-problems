#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> llp;
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

bool DESC(const pair<int,int> &a,const pair<int,int> &b)
{
       return a.first<b.first;
}

auto PAIR = [](pair<int,int> e1, pair<int,int> e2) {
    return e1.second<e2.second;
};

// g++ -std=c++11 -O2 -Wall test.cpp -o test
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, ans = 0;
        cin >> n;
        vector<ii> a(n);
        fori(i, n)
        {
            cin >> a[i].first >> a[i].second;
        }

        sort(all(a), DESC);

        // TODO: This low index should work well
        fori(i, n) {
            ii p = a[i];
            auto it = lower_bound(next(a.begin(), i), a.end(), p, PAIR);
            int low = distance(a.begin(), it);
            cout << i << " " << low << " " << ans << endl;
            ans += low - 1;
        }

        cout << ans << '\n';
    }
}