#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n,k;
        cin >> n >> k;
        if (n > k) {
            int cnt = n / k;
            if (n % k != 0) {
                cnt++;
            }
            k *= cnt;
        }
        int ans = (k + n - 1) / n;
        cout << ans << '\n';
    }
    return 0;
}