#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<bool> vb;

#define fori(i, n) for (int i = 0; i < (n); ++i)
#define fora(i, a, n) for (int i = a; i <= (n); ++i)

const int MAXN = 10e5 + 4;
int p[MAXN];

int main()
{
    int n;
    cin >> n;
    vi ans(n, -1);
    fori(i, n)
    {
        cin >> p[i];
    }

    fori(i, n)
    {
        int c = 0;
        int max = INT_MIN;
        fora(a, i, n)
        {
            if (a >= n)
            {
                a %= n;
            }
            if (p[a] > max)
            {
                max = p[a];
            }
            // cout << p[a] << " " << max / 2;

            if (p[a] <= (max / 2))
            {
                break;
            }
            else
            {
                c++; // check -1 cases
            }
        }
        // cout << endl;
        ans[i] = c;
    }

    fori(i, n)
    {
        cout << " " << ans[i];
    }
    cout << endl;
}