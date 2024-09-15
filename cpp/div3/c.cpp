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

void calc(int n, vector<vector<int>> &prefixA)
{
    fora(i, 1, n)
    {
        char c;
        cin >> c;
        prefixA[i][c - 'a']++;

        fori(j, 26) {
            prefixA[i][j] += prefixA[i-1][j];
        }
    }
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        
        vector<vector<int>> prefixA(n + 1, vector<int>(26, 0));
        vector<vector<int>> prefixB(n + 1, vector<int>(26, 0));

        calc(n, prefixA);
        calc(n, prefixB);

        fori(i, q)
        {
            int l, r;
            cin >> l >> r;
            int ans = 0;
            fori(c, 26) {
                int ans1 = prefixA[r][c] - prefixA[l-1][c];
                int ans2 = prefixB[r][c] - prefixB[l-1][c];

                ans += abs(ans1 - ans2);
            }

            cout << ans << endl;
        }
    }
    return 0;
}