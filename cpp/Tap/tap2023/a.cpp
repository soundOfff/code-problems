#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ii> vp;
typedef vector<long long int> vll;
typedef vector<char> vc;
typedef long double ld;

#define fori(i, n) for (int i = 0; i < (n); ++i)
#define fora(i, a, n) for (int i = a; i <= (n); ++i)
#define ford(i, a, n) for (int i = a; i >= (n); --i)

const int MAXN = 10e5 + 10;

#define X_MAX_NUM_STATIONS_DIFF 500000

ll n, m;
vl A;
vl O;

int main()
{
    cin >> n >> m;
    fori(i, n)
    {
        ll a;
        cin >> a;
        A.push_back(a);
    };
    fori(i, m)
    {
        ll a;
        cin >> a;
        O.push_back(a);
    };

    // sort(O.begin(), O.end());

    vi ans(n, 0);

    fori(i, n)
    {
        ll aux = A[i];

        int l = 0;
        int r = m - 1;
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (O[mid] < aux)
            {
                aux = aux % mid;
                l = mid + 1;
            }
            else
            {
                l++;
            }
        }
        fori(j, m)
        {
            if (aux % O[j] == aux)
            {
                continue;
            }
            else
            {
                aux %= O[j];
                ans[i] = aux;
            }
        }
    }

    fori(i, n)
    {
        cout << " " << ans[i];
    }
    cout << endl;
    return 0;
}