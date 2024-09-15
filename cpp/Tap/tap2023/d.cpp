#include <bits/stdc++.h>

typedef long long ll;

#define fori(i, n) for (int i = 0; i < (n); ++i)
#define fora(i, a, n) for (int i = a; i <= (n); ++i)
#define ford(i, a, n) for (int i = a; i >= (n); --i)

using namespace std;

int main(void)
{
    ll k;
    cin >> k;
    vector<ll> C(k);
    vector<ll> P(k);

    fori(i, k) cin >> C[i];
    fori(j, k) cin >> P[j];

    if (P[0] == 0)
    {
        cout << 0 << endl;
    }
    else
    {
        ll m_v = P[0] / C[0];
        ll p = P[0];
        ll c = C[0];

        fora(z, 1, k-1)
        {
            p += P[z];
            c += C[z];
            m_v = min(m_v, p / c);
        }

        cout << m_v << endl;
    }
    return 0;
}