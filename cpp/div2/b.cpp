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
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int op = 0;
        int c_p = 0, c_i = 0;
        bool flag = false;
        vi a(n);
        fori(i, n)
        {
            int ai;
            cin >> ai;
            a[i] = ai;
            if (ai % 2 != 0)
            {
                c_i++;
            }
            else
            {
                c_p++;
            }
        };

        if (c_i == 0 || c_p == 0)
        {
            flag = true;
        }

        if (!flag)
        {
            sort(a.begin(), a.end());

            int an = -1;
            fori(j, n)
            {
                if (an == -1 && a[j] % 2 != 0)
                {
                    an = a[j];
                    if (j == 0)
                        break;

                    continue;
                }
                if ((an + a[j - 1]) < a[j] && an != -1)
                {
                    op++;
                }
            }

            cout << (c_p + op) << '\n';
        }
        else
        {
            cout << 0 << '\n';
        }
    }
}