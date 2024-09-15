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

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 3;

#define _ % MOD
#define __ %= MOD

#define fori(i, n) for (int i = 0; i < (n); ++i)
#define fora(i, a, n) for (int i = a; i <= (n); ++i)
#define ford(i, a, n) for (int i = a; i >= (n); --i)

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string movs;
        vi prefix(n + 1, 0);
        vi p(n);
        fori(i, n) cin >> p[i];

        fori(i, n)
        {
            prefix[i + 1] = prefix[i] + p[i];
        }

        ll ans = 0;

        int l = 0, r = n - 1;
        while (l < r)
        {
            fora(i, l, r - 1)
            {
                if (movs[l] != 'L')
                    l++;
            }
            fora(i, l, r - 1)
            {
                if (movs[l] != 'R')
                    r++;
            }

            if (l < r)
                ans += prefix[r + 1] - prefix[l];

            l++;
            r--;
        }
        cout << ans << endl;
    }
}