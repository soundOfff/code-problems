#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
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
const int MAXN = 3000 + 10;

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

#define fi first
#define se second
#define mp make_pair
#define pb push_back

int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	int n1 = s1.size();
	int n2 = s2.size();
	int dp[n1 + 1][n2 + 1];
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= n1; ++i)
	{
		for (int j = 1; j <= n2; ++j)
		{
			if (s1[i - 1] == s2[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	string s;
	for (int i = n1, j = n2; i >= 1 && j >= 1;)
	{
		{
			if (s1[i - 1] == s2[j - 1])
			{
				s.push_back(s1[i - 1]);
				i--;
				j--;
			}
			else
			{
				if (dp[i - 1][j] > dp[i][j - 1])
					i--;
				else
					j--;
			}
		}
	}
	reverse(s.begin(), s.end()); //
	cout << s << endl;
}