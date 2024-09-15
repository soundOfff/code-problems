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
        t[v] = min(t[v*2+1], t[v*2+2]);
    }
}

int qry(int l, int r, int v = 0, int tl = 0, int tr = n-1) {
    if (l > r) 
        return INT_MAX;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return min(qry(l, min(r, tm), v*2+1, tl, tm), qry(max(l, tm+1), r, v*2+2, tm+1, tr));
}

void update(int pos, int new_val, int v = 0, int tl = 0, int tr = n-1) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(pos, new_val, v*2+1, tl, tm);
        else
            update(pos, new_val, v*2+2, tm+1, tr);
        t[v] = min(t[v*2+1], t[v*2+2]);
    }
}

int main() {
    cin >> n >> q;
    vector<int> arr(n);

    fori(i, n) cin >> arr[i];

    build(arr);

    fori(i, q) {
        int op, a, b;
        cin >> op >> a >> b;
        if (op == 1) {
            a--;
            update(a, b);
        } else {
            a--;
            b--;
            cout << qry(a, b) << endl;
        }
    }
}