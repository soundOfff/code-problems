#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int j = 0;
    for (int i = 0;; i++)
    {
        if (a[j] <= i)
        {
            cout << j + 1 << '\n';
            break;
        }
        j += 1;
        if (j >= n)
        {
            j = 0;
        }
    }
}