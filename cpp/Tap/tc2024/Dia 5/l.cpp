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
    ll b, v, o;
    ll eb, ev, eo;
    ll c[3];

    cin >> b >> v >> o;
    cin >> eb >> ev >> eo;

    c[0] = b - eb;
    c[1] = v - ev;
    c[2] = o - eo;

    bool flag = true;
    bool neg = false;

    if (c[0] < 0 && c[1] < 0 && c[2] < 0)
    {
        neg = true;
        flag = false;
    };

    if (c[0] < 0 && c[1] < 0 && (c[2] / 2 < c[0] + c[1]))
    {
        neg = true;
        flag = false;
    }

    if (c[0] < 0 && c[2] < 0 && (c[1] / 2 < c[0] + c[2]))
    {
        neg = true;
        flag = false;
    }

    if (c[1] < 0 && c[2] < 0 && (c[0] / 2 < c[1] + c[2]))
    {
        neg = true;
        flag = false;
    }

    cout << c[0] << c[1] << c[2] << endl;

    if (c[0] < 0 && !neg)
    {
        ll sobra1 = c[1] / 2;
        ll sobra2 = c[2] / 2;
        if (sobra1 + sobra2 < abs(c[0]))
        {
            flag = false;
        }
        else
        {
            if (c[1] >= abs(c[0]))
            {
                c[1] = (sobra1 - abs(c[0])) * 2;
            }
            else if (c[2] >= abs(c[0]))
            {
                c[2] = (sobra2 - abs(c[0])) * 2;
            }
            else
            {
                c[0] += sobra1;
                c[1] -= sobra1 * 2;
                c[2] = (sobra2 - abs(c[0])) * 2;
            }
            // ok
            c[0] = 0;
        }
    }
    if (c[1] < 0 && !neg)
    {
        ll sobra0 = c[0] / 2;
        ll sobra2 = c[2] / 2;
        if (sobra0 + sobra2 < abs(c[1]))
        {
            flag = false;
        }
        else
        {
            if (c[0] >= abs(c[1]))
            {
                c[0] = (sobra0 - abs(c[1])) * 2;
            }
            else if (c[2] >= abs(c[1]))
            {
                c[2] = (sobra2 - abs(c[1])) * 2;
            }
            else
            {
                c[1] += sobra0;
                c[0] -= sobra0 * 2;
                c[2] = (sobra2 - abs(c[1])) * 2;
            }
            // ok
            c[1] = 0;
        }
    }
    if (c[2] < 0 && !neg)
    {
        ll sobra1 = c[1] / 2;
        ll sobra0 = c[0] / 2;
        if (sobra1 + sobra0 < abs(c[2]))
        {
            flag = false;
        }
        else
        {
            if (c[1] >= abs(c[2]))
            {
                c[1] = (sobra1 - abs(c[2])) * 2;
            }
            else if (c[0] >= abs(c[2]))
            {
                c[0] = (sobra0 - abs(c[2])) * 2;
            }
            else
            {
                c[2] += sobra1;
                c[1] -= sobra1 * 2;
                c[0] = (sobra0 - abs(c[2])) * 2;
            }
            // ok
            c[2] = 0;
        }
    }

    cout << (flag ? "YES" : "NO") << endl;
}