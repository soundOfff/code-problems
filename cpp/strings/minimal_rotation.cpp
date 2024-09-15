#include <bits/stdc++.h>
#include <cmath>

#define ll long long

#define fori(i, n) for (int i = 0; i < (n); ++i)
#define fora(i, a, n) for (int i = a; i <= (n); ++i)
#define ford(i, a, n) for (int i = a; i >= (n); --i)

using namespace std;

int main() {
    string str;
    cin >> str;
    int n = str.size();
    const int p = 31;
    const int m = 1e9 + 9;
    vector<long long> p_pow(n);
    p_pow[0] = 1;
    for (int i = 1; i < n; i++)
        p_pow[i] = (p_pow[i-1] * p) % m;

    vector<long long> h(n + 1, 0);
    fori(i,n)
        h[i+1] = (h[i] + (str[i] - 'a' + 1) * p_pow[i]) % m;
    
    fori(i, n+1) cout << h[i] << endl;
    // fori(i, int(str.length())) {
    //     rotate(str.begin(), str.begin() + 1, str.end());
    //     if (str.compare(min) < 0) {
    //         min = str;
    //     }
    // }

    // cout << min << endl;
}