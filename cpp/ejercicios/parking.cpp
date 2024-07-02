#include <bits/stdc++.h>

using namespace std;


int main()
{
    int h, m, n, x, y;
    cin >> h >> m;
    cin >> n;
    int tm = h * 60 + m;
    int acum = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        if (tm >= x) {
            acum += x*y;
            tm -= x;
        } else {
            acum += tm*y;
            tm = 0;
            break;
        }
    }


    cout << acum << '\n';
}
