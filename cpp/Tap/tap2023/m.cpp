#include <bits/stdc++.h>

typedef long long ll;

#define fori(i, n) for (int i = 0; i < (n); ++i)
#define fora(i, a, n) for (int i = a; i <= (n); ++i)
#define ford(i, a, n) for (int i = a; i >= (n); --i)

using namespace std;

int main()
{
    int n;
    int ans = 0;
    vector<pair<int, int>> points;
    cin >> n;
    fori(i, n)
    {
        int a, b;
        cin >> a >> b;
        points.push_back({a, b});
    }

    fori(i, n)
    {
        auto x1 = points[i];
        fori(j, n)
        {
            auto x2 = points[j];
            if (x1 == x1)
                continue;
            fori(z, n)
            {
                auto x3 = points[z];
                if (x2 == x3 || x1 == x3)
                    continue;
                int d12 = sqrt(pow(x1.first - x2.first, 2) + pow(x1.second - x2.second, 2));
                int d13 = sqrt(pow(x1.first - x3.first, 2) + pow(x1.second - x3.second, 2));
                int d23 = sqrt(pow(x2.first - x3.first, 2) + pow(x2.second - x3.second, 2));

                if ((d12*d12) == (d13*d13) + (d23*d23)) ans++;
                if ((d13*d13) == (d12*d12) + (d23*d23)) ans++;
                if ((d23*d23) == (d13*d13) + (d12*d12)) ans++;
            }
        }
    }
}