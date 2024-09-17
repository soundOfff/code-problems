#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll ice_shops[200010], people[200010];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, m;
    map<ll, ll> range;
    cin >> n >> m;

    for (ll i = 1; i <= n; i++)
        cin >> people[i];

    for (ll i = 1; i <= m; i++)
        cin >> ice_shops[i];

    sort(ice_shops + 1, ice_shops + m + 1);
    ice_shops[0] = -2e9 + 5, ice_shops[m + 1] = 2e9 + 5;

    for (ll i = 1; i <= n; i++)
    {
        ll d = (i - 1) * 100;
        ll a = lower_bound(ice_shops, ice_shops + m + 2, d) - ice_shops;
        ll mn = min(ice_shops[a] - d, d - ice_shops[a - 1]);
        range[d - mn] += people[i];
        range[d + mn] -= people[i]; // for clear the interval in that range when sum
    }

    ll ans = 0, t = 0;
    for (auto u : range)
    {
        t += u.second;
        ans = max(ans, t);
    }

    cout << ans << endl;
    return 0;
}
