#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vp;
typedef vector<long long int> vll;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef long double ld;

typedef set<int>::iterator sit;
typedef map<int, int>::iterator mit;
typedef vector<int>::iterator vit;
typedef vector<long long int>::iterator vllit;

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 3;

#define each(it, s) for (vit it = s.begin(); it != s.end(); ++it)
#define sortAsc(v) sort(v.begin(), v.end())
#define sortDesc(v) sort(v.begin(), v.end(), greater<auto>())
#define fill(a, v) memset(a, v, sizeof(a))

#define fori(i, n) for (int i = 0; i < (n); ++i)
#define fora(i, a, n) for (int i = a; i <= (n); ++i)
#define ford(i, a, n) for (int i = a; i >= (n); --i)
#define pq(x) priority_queue<x, std::vector<x>, compare>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define fbo find_by_order
#define ook order_of_key

int dp[1010][1010];
vs grid;
int ROWS, COLS;

int solve(int row, int col)
{
    // Base cases
    if (row > ROWS - 1 || col > COLS - 1)
        return 0;
    if (grid[row][col] == '#')
        return 0;
    if (dp[row][col] != -1)
        return dp[row][col];
    if (row == ROWS - 1 && col == COLS - 1)
        return 1; // reached the exit

    return dp[row][col] = (solve(row + 1, col) + solve(row, col + 1)) % MOD;
}

int main()
{
    cin >> ROWS >> COLS;
    for (int i = 0; i < ROWS; i++)
    {
        string s;
        cin >> s;
        grid.push_back(s);
    }
    fill(dp, -1);

    cout << solve(0, 0) << '\n';

    return 0;
}