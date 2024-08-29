#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<string> vs;
typedef vector<bool> vb;

#define fori(i, n) for (int i = 0; i < (n); ++i)
#define fora(i, a, n) for (int i = a; i <= (n); ++i)

const int MAXN = 200031;

map<ll, vl> comp;
ll ANS[MAXN], gtr = 0;

int main()
{
    int n, m;
    cin >> n >> m;
    fori(i, n)
    {
        ll si, ri;
        cin >> si >> ri;
        comp[si].push_back(ri);
    }

    fora(j, 1, m)
    {
        sort(comp[j].rbegin(), comp[j].rend());
        ll aux = 0;
        fori(k, int(comp[j].size()))
        {
            aux += comp[j][k];
            if (aux > 0) // filter negatives
            {
                ANS[k + 1] += aux;
            }
        }
    }

    fora(i, 1, n)
    {
        gtr = max(gtr, ANS[i]);
    }

    cout << gtr << endl;
}