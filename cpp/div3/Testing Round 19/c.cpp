#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 3;

#define _ % MOD
#define __ %= MOD

#define fori(i, n) for (int i = 0; i < (n); ++i)
#define fora(i, a, n) for (int i = a; i <= (n); ++i)
#define ford(i, a, n) for (int i = a; i >= (n); --i)

vector<int> z_fun(string s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    fora(i, 1, n-1) {
        if (i < r) {
            z[i] = min(r-i, z[i-l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) 
        {
            z[i]++;
        }
        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }   
    }

    return z;
}

int main()
{
    string s;
    cin >> s;
    auto z = z_fun(s);
    int n = s.size();
    int index = -1;
    fora(i, 1, n-1) {
        if (z[i] >= (n - i) && z[i] > i) {
            index = i;
        }
    }

    if (index != -1 ) {
        cout << "YES" << endl;
        fora(i, index, n-1) {
            cout << s[i];
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
    }
}
