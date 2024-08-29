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

int solve(int n, int b[])
{
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        int b[n];
        fori(i, n) cin >> b[i];
        cout << solve(n, b) << endl;
    }
}