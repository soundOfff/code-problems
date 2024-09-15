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

typedef set<int>::iterator sit;
typedef map<int, int>::iterator mit;
typedef vector<int>::iterator vit;
typedef vector<long long int>::iterator vllit;

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 3;

#define _ % MOD
#define __ %= MOD

#define each(it, s) for (vit it = s.begin(); it != s.end(); ++it)
#define sortAsc(v) sort(v.begin(), v.end())
#define sortDesc(v) sort(v.begin(), v.end(), greater<auto>())
#define fill(a, v) memset(a, v, sizeof(a))

#define fori(i, n) for (int i = 0; i < (n); ++i)
#define fora(i, a, n) for (int i = a; i <= (n); ++i)
#define ford(i, a, n) for (int i = a; i >= (n); --i)
#define pq(x) priority_queue<x, std::vector<x>, compare>

#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define min4(a, b, c, d) min(a, min(b, min(c, d)))
#define max4(a, b, c, d) max(a, max(b, max(c, d)))

#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define fbo find_by_order
#define ook order_of_key

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        ll score = 0;
        cin >> n >> k;
        deque<pair<ll, ll>> values(n);
        fori(i, n) {
            int ai;
            cin >> ai;
            values[i].first = ai;
            values[i].second = 0;
        }
        fori(i, n) {
            ll bi;
            cin >> bi;
            values[i].second = bi;
        }
    
        sort(values.rbegin(), values.rend());
        // N LOG N not working in 2 seconds 10 ^ 9 
        while (k--)
        {
            auto val = values[0];
            score += val.first;
            ll mod_v = max(0LL, (val.first - val.second));
            if (mod_v == 0) {
                values.pop_front();
            } else if (mod_v >= val.first) {
                ii pair;
                pair.first = mod_v;
                pair.second = val.second;
                values.pop_front();
                values.push_back(pair);
            } else {
                values[0].first = mod_v;
            }
            for (auto &p : values) {
                cout << p.first << "-" << p.second;
            } cout << endl;
            // sort(values.rbegin(), values.rend());
        }
        
        cout << score << endl;
    }
    return 0;
}
