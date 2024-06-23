#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vp;
typedef vector<long long int> vll;
typedef vector<char> vc;
typedef long double ld;

typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;
typedef vector<long long int>::iterator vllit;

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 3;

#define _  %  MOD
#define __ %= MOD

#define      each(it,s)        for(vit it = s.begin(); it != s.end(); ++it)
#define      sortAsc(v)          sort(v.begin(), v.end())
#define      sortDesc(v)          sort(v.begin(), v.end(), greater<auto>())
#define      fill(a, v)           memset(a, v, sizeof (a))

#define      fori(i, n)         for(int i = 0; i < (n); ++i)
#define      fora(i, a, n)     for(int i = a; i <= (n); ++i)
#define      ford(i, a, n)     for(int i = a; i >= (n); --i)
#define 	 pq(x)			   priority_queue<x,std::vector<x>,compare>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define fbo find_by_order
#define ook order_of_key

int n;
int a[MAXN];

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve() {
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int acum = 0;
        fora(i, 1, n) {
            cin >> a[i];
            if (i<n) {
                acum = max(acum, a[i]);
            }
        }
        acum += a[n];
        cout<<acum<<'\n';
    }
}

int main() {
    init();
    solve();
}