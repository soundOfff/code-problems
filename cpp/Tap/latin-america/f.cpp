#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define int long long

int32_t main()
{
    int n;
    cin >> n;
    vector<pair<int, pair<int, int>>> info(n);
    for (int i = 0; i < n; ++i)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        info[i] = {a, {b, c}};
    }

    sort(info.begin(), info.end(), [](const auto &x, const auto &y)
         {
             if (x.first == y.first)
                 return x.second.first > y.second.first; 
             return x.first > y.first; });

    auto gtr = info[0];
    int ans = gtr.second.second;

    for (int i = 1; i < n; ++i)
    {
        if (gtr.first > info[i].first && gtr.second.first > info[i].second.first)
        {
            ans += info[i].second.second;
        }
        else if (gtr.first == info[i].first && gtr.second.first == info[i].second.first)
        {
            ans += info[i].second.second;
        }
    }

    cout << ans << endl;
    return 0;
}
