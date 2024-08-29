#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define pb push_back

#define MAXN 1000005

signed main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    vector<int> B(n);
    for (int i = 0; i < n; i++)
        cin >> B[i];
    sort(A.begin(), A.end());
    sort(B.rbegin(), B.rend());
    vector<int> c;
    for (int i = 0; i < n; i++)
        c.pb(A[i] + B[i]);
    int ans = *max_element(c.begin(), c.end()) - *min_element(c.begin(), c.end());
    cout << ans << endl;
    return 0;
}