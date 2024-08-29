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
    int n, k;
    string c;
    cin >> n >> k;
    vl dmg;
    ll tot = 0;
    fori(i, n)
    {
        ll ai;
        cin >> ai;
        dmg.pb(ai);
    }
    cin >> c;

    fora(i, 1, int(c.length()))
    {
        char prev_mov = c[i - 1];
        char curr_mov = c[i];
        if (prev_mov != curr_mov)
        {
            tot += dmg[i - 1];
        }
        else
        {
            vl aux;
            fora(j, i - 1, i + k - 2)
            {
                if (c[i] == c[j])
                {
                    aux.pb(dmg[j]);
                }
            }
            i += k;
            fori(cc, int(aux.size()))
            {
                cout << aux[cc];
            }
            cout << endl;
            if (int(aux.size()) > k)
            {
                sort(rall(aux));
                fori(kk, k)
                {
                    tot += aux[kk];
                }
            }
            else
            {
                for (int i : aux)
                {
                    tot += i;
                }
            }
        }
    }

    cout << tot << endl;
}