#include <bits/stdc++.h>

typedef long long ll;

#define fori(i, n) for (int i = 0; i < (n); ++i)
#define fora(i, a, n) for (int i = a; i <= (n); ++i)
#define ford(i, a, n) for (int i = a; i >= (n); --i)

using namespace std;

int main()
{
    ll m, d1, n, d2, d;
    ll ans = 0;
    cin >> d >> m >> d1 >> n >> d2;
    vector<ll> md(m);
    vector<ll> nd(n);

    fora(i, 1, m)
    {
        md[i] = md[i - 1] + d1;
    }

    fora(i, 1, n)
    {
        nd[i] = nd[i - 1] + d2;
    }
    d*=2;

    auto m_index = lower_bound(md.begin(), md.end(), d) - md.begin();
    ans += m_index;
    d -= md[m_index];
    d*=2;
    if (d <= 0)
    {
        cout << ans << endl;
    }
    else
    {
        auto n_index = lower_bound(md.begin(), md.end(), d) - md.begin();
        ans += n_index;
        d -= nd[n_index];
        if (d <= 0) {
            cout << ans << endl;
        } else {
            cout << -1 << endl;
        }
    }
}