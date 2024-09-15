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

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 3;

#define _ % MOD
#define __ %= MOD

#define fori(i, n) for (int i = 0; i < (n); ++i)
#define fora(i, a, n) for (int i = a; i <= (n); ++i)
#define ford(i, a, n) for (int i = a; i >= (n); --i)
#define pq(x) priority_queue<x, std::vector<x>, compare>

#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define min4(a, b, c, d) min(a, min(b, min(c, d)))
#define max4(a, b, c, d) max(a, max(b, max(c, d)))

#define pb push_back

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        int n,k;
        cin >> n >> k;
        int sum = n * (n - 1) / 2;
        sum += n * k;

        int l = k, r = k+n-1;
        int m = INT_MAX;

        while (l - r > 1)
        {
            int m = (l+r) >> 1;
        }
        
        // for (int i = k+n-1; i >= k; --i) {
        //     int sum = ((i-1)*i) / 2;
        //     int sumL = abs(sumK - sum);
        //     int sumR = abs(sumT - sum);
        //     m = min(m, abs(sumL - sumR));
        // }

        cout << m << endl;
    }
    return 0;
}