#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000006;

#define fori(i, n) for (int i = 0; i < (n); ++i)
#define fora(i, a, n) for (int i = a; i <= (n); ++i)
#define ford(i, a, n) for (int i = a; i >= (n); --i)

#define pb push_back

#define int long long

int get_val(int n)
{
    int s = 0;
    while (n)
    {
        s += n % 10;
        n /= 10;
    }
    return s;
}

int32_t main()
{
    int n, k;
    cin >> n >> k;

    vector<int> vals(MAXN);

    fori(i, n)
    {
        int a;
        cin >> a;
        vals[a]++;
    }

    ford(i, MAXN, 0)
    {
        if (vals[i] == 0)
            continue;

        int polen = get_val(i);
        k -= vals[i];
        if (k <= 0)
        {
            cout << polen << endl;
            return 0;
        }
        vals[i - polen] += vals[i];
    }

    return 0;
}
