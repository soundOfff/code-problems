#include <bits/stdc++.h>
#include <cmath>

#define ll long long

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<ll> a;
        ll n;
        ll max = -1;
        ll ans = 0;
        cin >> n;
        for (ll i = 0; i < n; i++)
        {
            ll ai;
            cin >> ai;
            a.push_back(ai);
            if (ai > max)
            {
                max = ai;
            }
        }

        for (int j = 0; j < n; j++)
        {
            for (int k = n - 1; k >= 1; k++)
            {
                auto aux = std::vector<int>(a.begin() + 1, a.end()); // TODO find a way to make subarrays more easily and get the max
            }
        }
    }
}