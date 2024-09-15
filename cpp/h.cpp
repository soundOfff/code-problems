#include <bits/stdc++.h>
#define MAX 100005

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

int colors[MAX][2];

int main()
{
    int n, c;
    cin >> n >> c;
    fori(i, n)
    {
        int x, color;
        cin >> x >> color;
        colors[i][0] = x;
        colors[i][1] = color;
    }

    fori(i, n)
    {
        if (colors[i][0] != i + 1 && colors[i][1] != colors[colors[i][0] - 1][1])
        {
            cout << "N\n";
            return 0;
        }
    }
    cout << "Y\n";
    return 0;
}