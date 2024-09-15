#include <bits/stdc++.h>
#include <cmath>

#define int long long

#define fori(i, n) for (int i = 0; i < (n); ++i)
#define fora(i, a, n) for (int i = a; i <= (n); ++i)
#define ford(i, a, n) for (int i = a; i >= (n); --i)

using namespace std;

const int MAXN = 200005;
const int K = 20;

int st[K][MAXN];

int32_t main()
{
    int n, q;
    cin >> n >> q;
    vector<int> p(n);

    fori(i, n) cin >> p[i];

    std::copy(p.begin(), p.end(), st[0]);

    for (int i = 1; i <= K; i++)
        for (int j = 0; j + (1 << i) <= n; j++)
            st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);

    fori(i, q)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        int k = log2(r - l + 1);

        cout << min(st[k][l], st[k][r - (1 << k) + 1]) << endl;
    }
}