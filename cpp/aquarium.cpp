#include <bits/stdc++.h>

#define int long long

using namespace std;

int binary_search(vector<int> &a, int x, int n)
{
    int l = 1, r = 1e18, ans = 0;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        int water = 0;
        for (int i = 0; i < n; i++)
        {
            if (mid > a[i]) {
                water += mid - a[i];
            }
        };

        if (water <= x)
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
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int result = binary_search(a, x, n);
        cout << result << '\n';
    }
}