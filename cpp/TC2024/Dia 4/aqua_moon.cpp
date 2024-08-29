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
const int MAXN = 1e5 + 3;

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

string board;
vector<bool> visited(MAXN, false); // The idea here is on the recursion convert the 01110 str to number and mark as true on the array
int ans = 1;                       // counts the initial solve

string can_move_next(string &board)
{
    string aux = board;
    bool f = false;
    fori(i, int(aux.length() - 2))
    {
        if (aux[i] == '1' && aux[i + 1] == '1' && aux[i + 2] == '0')
        {
            aux[i + 2] = aux[i + 1];
            aux[i] = '0';
            f = true;
        }
    }

    return (f ? aux : "");
}

string can_move_back(string &board)
{
    string aux = board;
    bool f = false;
    fora(i, 1, int(aux.length() - 1))
    {
        if (aux[i] == '1' && aux[i + 1] == '1' && aux[i - 1] == '0')
        {
            aux[i - 1] = aux[i];
            aux[i] = '0';
            f = true;
        }
    }

    return (f ? aux : "");
}

int solve(string board)
{
    ll index = stoi(board, nullptr, 2);
    if (visited[index])
        return 0;
    visited[index] = true;
    auto str1 = can_move_next(board);
    auto str2 = can_move_back(board);

    if (str1 != "")
        ans += solve(str1);
    if (str2 != "")
        ans += solve(str2);

    return 1;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cin >> board;

        ans += solve(board);
        cout << ans << endl;
    }
}