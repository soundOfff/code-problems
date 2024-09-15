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

pair<int,int> get_min_seg(int min, int max, int ai, int k) {
    int m_m = ai;
    int m_x = (ai + k) - 1;
    int i = 0;
    while (m_x < min)
    {
        i+=2;
        m_m = ai + (i*k);
        m_x = ai + ((i+1)*k) - 1;
    }
    return { m_m, m_x };
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n,k;
        cin >> n >> k;
        vi a(n);
        vector<pair<int,int>> s;
        fori(i,n) cin >> a[i];

        sort(a.rbegin(), a.rend());

        pair<int,int> ai;
        ai.first = a[0];
        ai.second = (a[0] + k) - 1;
        int min_seg = a[0];
        s.push_back(ai);
        bool flag = true;

        fora(j, 1, n-1) {
            auto aj = get_min_seg(ai.first, ai.second, a[j], k);
            min_seg = max(min_seg, aj.first);
            s.push_back(aj);
        }

        fori(k, n) {
            if (s[k].second < min_seg) {
                flag = false;
                break;
            }
        }

        cout << (flag ? min_seg : -1) << endl;
    }
}