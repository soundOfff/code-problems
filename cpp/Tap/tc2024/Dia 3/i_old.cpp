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

    bool flag = true;
    fori(r, n)
    {
        fori(c, m)
        {
            if (matrix[r][c] == 0)
            {
                auto aux = max(matrix[r - 1][c], matrix[r][c - 1]);
                int ch;
                if (matrix[r + 1][c] == 0 || matrix[r][c + 1])
                {
                }

                if (aux + 1 == matrix[r + 1][c] || aux + 1 == matrix[r][c + 1])
                {
                    flag = false;
                    break;
                }
                else
                {
                    int min_aux = min(matrix[r + 1][c], matrix[r][c + 1]);
                    matrix[r][c] = min_aux + 1;
                }
            }
            if (matrix[r][c] < matrix[r - 1][c] || matrix[r][c] < matrix[r][c - 1])
            {
                flag = false;
                break;
            }
        }
        if (!flag)
        {
            break;
        }
    }

    if (flag)
    {
        int acum = 0;
        fori(i, n)
        {
            fori(j, m)
            {
                acum += matrix[i][j];
            }
        }
        cout << acum << endl;
    }
    else
    {
        cout << -1 << endl;
    }

    return 0;
}