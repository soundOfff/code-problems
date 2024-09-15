#include <bits/stdc++.h>
#include <cmath>

#define int long long

#define fori(i, n) for (int i = 0; i < (n); ++i)
#define fora(i, a, n) for (int i = a; i <= (n); ++i)
#define ford(i, a, n) for (int i = a; i >= (n); --i)

using namespace std;

int32_t main()
{
    int n, q;
    cin >> n >> q;
    vector<int> prefix(n + 1, 0);

    fori(i, n)
    {
        int a;
        cin >> a;
        prefix[i + 1] = prefix[i] + a;
    }

    fori(i, q)
    {
        int l, r;
        cin >> l >> r;
        cout << prefix[r] - prefix[l - 1] << endl;
    }
}