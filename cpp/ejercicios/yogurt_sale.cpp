#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    int m = 0;
    for (int i = 0; i < t; i++)
    {
        int n, a, b;
        cin >> n >> a >> b;
        if (b > 2 * a)
        {
            m = a * n;
        }
        else
        {
            m = (n / 2) * b + (n % 2) * a;
        }
        cout << m << '\n';
    }
}