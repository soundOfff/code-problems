#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

const int MAXN = 10e6 + 3;

#define fori(i, n) for (int i = 0; i < (n); ++i)
#define fora(i, a, n) for (int i = a; i <= (n); ++i)
#define ford(i, a, n) for (int i = a; i >= (n); --i)

#include "iostream"
#include "vector"
#include "algorithm"


int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        set<int> s;
        fora(x, 1, n) {
            if (x * x > n) break;
            s.insert(x * x);
        }
        fora(x, 1, n) {
            if (x * x * x > n) break;
            s.insert(x * x * x);
        }

        cout << s.size() << endl;
    }
    return 0;
}