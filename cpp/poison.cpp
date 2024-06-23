#include <bits/stdc++.h>

#define int long long

using namespace std;

int binary_search(vector<int> &hits, int h, int n)
{
    int l = 1, r = h, mid, attack = 0, k = h;
    while (l <= r)
    {
        mid = (l + r) / 2;
        attack = 0;
        for (int i = 0; i < n - 1; i++) attack += min(mid, hits[i + 1] - hits[i]); // calculates damage for each mid = k
        attack += mid; // add the damage for the last hit
        if (attack >= h)
        {
            k = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    return k;
}

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int h, n;
        cin >> n >> h;
        vector<int> hits(n);
        for (int i = 0; i < n; i++)
        {
            cin >> hits[i];
        }
        int result = binary_search(hits, h, n);
        cout << result << '\n';
    }
}