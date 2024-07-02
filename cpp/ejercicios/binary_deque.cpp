#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int arr[n];
        int sm = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            sm += arr[i];
        }
        if (k > sm)
        {
            cout << -1 << '\n';
        }
        else
        {
            int op = 0, i = 0, j = 0;
            sm = 0;
            while (sm < k)
            {
                sm += arr[i];
                i += 1;
            }
            for (i; i < n && (arr[i] == 0); i++) {}
            op = i;
            while (i < n)
            {
                if (arr[i] == 0)
                {
                    op = max(op, i - j + 1);
                    i += 1;
                }
                else
                {
                    while (arr[j] != 1)
                    {
                        j += 1;
                    }
                    j += 1;
                    op = max(op, i - j + 1);
                    i += 1;
                }
            }
            cout << n - op << '\n';
        }
    }
}
