#include <bits/stdc++.h>

#define fori(i, n) for (int i = 0; i < (n); ++i)
#define fora(i, a, n) for (int i = a; i <= (n); ++i)

using namespace std;
const int MAXN = (int)1e6 + 5;

int n, q, t[4*MAXN];

void build(vector<int> &a, int v = 0, int tl = 0, int tr = n - 1) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2+1, tl, tm);
        build(a, v*2+2, tm+1, tr);
        t[v] = 0;
    }
}

int get(int pos, int v = 0, int tl = 0, int tr = n-1) {
    if (tl == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return t[v] + get(v*2, tl, tm, pos);
    else
        return t[v] + get(v*2+1, tm+1, tr, pos);
}

void update(int l, int r, int add, int v = 0, int tl = 0, int tr = n - 1) {
    if (l > r)
        return;
    if (l == tl && r == tr) {
        t[v] += add;
    } else {
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), add);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, add);
    }
}

int main() {
    cin >> n >> q;
    vector<int> arr(n);

    fori(i, n) cin >> arr[i];

    build(arr);

    fori(i, q) {
        int op;
        cin >> op;
        if (op == 1) {
            int a, b, u;
            cin >> a >> b >> u;
            a--; b--;
            update(a, b, u);
        } else {
            int a;
            cin >> a;
            a--;
            cout << get(a) << endl;
        }
    }
}