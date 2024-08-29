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
const int MAXN = 500 + 5;

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

int n, m;
int matrix[MAXN][MAXN];
bool visited[MAXN][MAXN];
bool isAscending = true;

int go(int row, int col, int source)
{
    if (visited[row][col])
        return matrix[row][col];
    visited[row][col] = true;

    if (matrix[row][col] != 0)
    {
        return matrix[row][col];
    }
    if (source == 1)
    {
        visited[row][col] = false;
        return matrix[row][col];
    }

    int a = go(row - 1, col, 1);
    int b = go(row, col - 1, 1);

    int c = go(row + 1, col, 0);
    int d = go(row, col + 1, 0);

    int ab = max(a, b);
    int cd = min(c, d);

    if (c - 1 > ab && d - 1 > ab) // not increasing
    {
        matrix[row][col] = cd - 1;
        return matrix[row][col];
    }
    else
    {
        // imposible, no completo
        isAscending = false;
        return go(n, m, 0);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    fori(i, n)
    {
        fori(j, m)
        {
            int ai;
            cin >> ai;
            matrix[i][j] = ai;
        }
    }
    fill(visited, false);

    ll sum = 0;
    fori(i, n)
    {
        fori(j, m)
        {
            sum += go(i, j, 0);
        }
    }
    ll sum2 = 0;
    fori(row, n)
    {
        fori(col, m)
        {
            if (matrix[row][col] == 0)
            {
                isAscending = false;
                break;
            }
            sum2 += matrix[row][col];
            if (col == m - 1 && row == n - 1)
            {
                break;
            }
            if (col == m - 1)
            {
                if (matrix[row][col] >= matrix[row + 1][col])
                {
                    isAscending = false;
                    break;
                }
            }
            else if (row == n - 1)
            {
                if (matrix[row][col] >= matrix[row][col + 1])
                {
                    isAscending = false;
                    break;
                }
            }
            else if (matrix[row][col] >= matrix[row + 1][col] || matrix[row][col] >= matrix[row][col + 1])
            {
                isAscending = false;
                break;
            }
        }
        if (!isAscending)
            break;
    }

    if (isAscending)
    {
        cout << max(sum, sum2) << endl;
    }
    else
    {
        cout << -1 << endl;
    }
    return 0;
}