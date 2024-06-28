#include <bits/stdc++.h>
#include <cmath>

#define ll long long

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, ans = INT_MIN, acum = INT_MIN;
        cin >> n;
        for (int x = 2; x <= n; x++)
        {
            int mid = n / x;
            int aux = mid * (mid + 1) * 2 * x;
            if (aux > acum)
            {
                ans = x;
                acum = aux;
            }
        }
        cout << ans << endl;
    }
}