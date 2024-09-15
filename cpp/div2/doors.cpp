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

const int MAXN = 100;


#define fori(i, n) for (int i = 0; i < (n); ++i)
#define fora(i, a, n) for (int i = a; i <= (n); ++i)
#define ford(i, a, n) for (int i = a; i >= (n); --i)

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        int l,r,L,R;
        cin >> l >> r;
        cin >> L >> R;

        if (l > L && r < L) {
            cout << 1 << endl;
        } else if (l == L && r == R) {
            cout << abs(r - l) << endl;
        } else if (L >= l && r >= R) {
            cout << abs(r - L) + abs(R - L) << endl;
        } else if (l > L && R > r) {
            cout << abs(r - L) << endl;
        }

    }
}