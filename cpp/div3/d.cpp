#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;

const int MAXN = 10e6 + 3;

#define fori(i, n) for (int i = 0; i < (n); ++i)
#define fora(i, a, n) for (int i = a; i <= (n); ++i)
#define ford(i, a, n) for (int i = a; i >= (n); --i)

#include "iostream"
#include "vector"
#include "algorithm"

int main() {
    ll t;
    cin >> t;
    while (t--)
    {
        ll n,x;
        ll ans = 0;
        cin >> n >> x;

        fora(a, 1, min(n,x)) {
            fora(b, 1, min(n,x)) {
                if (a * b >= n) break;
                if (a + b >= x) break;
                ll h_c = min((n - a * b) / (a + b), x - (a + b));
                ans += h_c;
            }
        }

        cout << ans << endl;
    }
    return 0;
}