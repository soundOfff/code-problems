
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<bool> vb;

#define fori(i, n) for (int i = 0; i < (n); ++i)
#define fora(i, a, n) for (int i = a; i <= (n); ++i)

#define int long long

const int MAXN = 20e5 + 4;
int p[MAXN];

int32_t main()
{
    int n, m;
    cin >> n >> m;
    vi people;
    vi ice_shops;

    fori(i, n)
    {
        int a;
        cin >> a;
        people.push_back(a);
    }
    fori(i, m)
    {
        int b;
        cin >> b;
        ice_shops.push_back(b);
    }

    sort(ice_shops.begin(), ice_shops.end());

    vi range(n, 0);

    int m_i = 0;
    int r_i = 0;

    fori(k, n)
    {
        if (m_i < m && ice_shops[m_i] / 101 == k)
        {
            if (k == 0 && ice_shops[m_i] != 1)
            {
                range[r_i] += people[k];
            }
            else if (k != 0 && (k * 100) + 1 != ice_shops[m_i])
            {
                range[r_i] += people[k];
            }
            m_i++;
            r_i++;
        }
        else
        {
            range[r_i] += people[k];
        }
    }

    auto test = max_element(range.begin(), range.end());

    cout << range[test - range.begin()] << endl;

    return 0;
}
