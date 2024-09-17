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
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int max_r = INT_MIN, max_w = INT_MIN;

        fori(i, m)
        {
            int red, white;
            cin >> red >> white;
            if (red > max_r)
            {
                max_r = red;
            }
            else if (white > max_w)
            {
                max_w = white;
            }
        }

        string solve = "";
        if (max_w + max_r > n)
        {
            cout << "IMPOSSIBLE" << endl;
        }
        else
        {
            fori(i, max_r)
            {
                solve += "R";
            }
            fori(i, max_w)
            {
                solve += "W";
            }
        }

        cout << solve << endl;
    }
}