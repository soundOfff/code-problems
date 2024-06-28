#include <bits/stdc++.h>
#include <cmath>

#define ll long long

using namespace std;

int main()
{
    ll t;
    cin >> t;
    for (ll i = 0; i < t; i++)
    {
        ll n;
        cin >> n;
        ll sum = 0;
        for (ll j = 0; j < n; j++)
        {
            ll a;
            cin >> a;
            sum += a;
        }
        bool isPerfectSquare = false;
        for (ll k = 0; k <= sqrt(sum); k++)
        {
            if (k * k > sum)
            {
                break;
            }
            if (k * k == sum)
            {
                cout << "YES" << "\n";
                isPerfectSquare = true;
                break;
            }
        }
        if (!isPerfectSquare)
        {
            cout << "NO" << "\n";
        }
    }
}
