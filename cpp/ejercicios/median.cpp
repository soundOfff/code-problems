#include <bits/stdc++.h>

#define int long long

using namespace std;

int binary_search(int n, int s)
{
    int l = n, r = s, ans = s;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        int sum = 0;
        for (int i = n; i <= r; i++) sum += i;

        if (sum <= s)
        {
            ans = mid;
            l = mid + 1;
        } else
        {
            r = mid - 1;
        }
    }
    return ans;
}

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, s;
        cin >> n >> s;
        int r = binary_search(n, s);
        cout << r << '\n';
    }
}