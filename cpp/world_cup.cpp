#include <bits/stdc++.h>
#include <cmath>

#define ll long long

using namespace std;

void reduce_one(vector<ll> &a, int index)
{
    if (a[index] > 0)
    {
        a[index]--;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i)
        cin >> a[i];

    ll k = 0;
    while (a[k % n] != 0)
    {
        reduce_one(a, k % n);
        k++;
    }
    cout << k << '\n';
    return 0;
}