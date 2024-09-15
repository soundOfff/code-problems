#include <bits/stdc++.h>
#include <cmath>

#define int long long

#define fori(i, n) for (int i = 0; i < (n); ++i)
#define fora(i, a, n) for (int i = a; i <= (n); ++i)
#define ford(i, a, n) for (int i = a; i >= (n); --i)

using namespace std;

const int N = 200005;
int tree[2*N];
int n;

void update(int k, int x){
    k+=n;
    while(k>=1){
        tree[k] += x;
        k>>=1;
    }
}
int sum(int a, int b){
    a+=n, b+=n;
    int s = 0;
    while(a<=b){
        if (a&1) s+= tree[a++]; //a is right child
        if (~b&1) s+= tree[b--]; // b is left child
        a>>=1, b>>=1;
    }
    return s;
}

int32_t main()
{
    int q;
    cin >> n >> q;

    fori(i, n) {
        int a; cin >> a;
        update(i, a);
    };

    fori(i, q)
    {
        int k, l, r;
        cin >> k >> l >> r;
        if (k == 1) {
            int x = tree[l-1+n];
            update(l-1,r-x);
        } else {
            cout << sum(l-1,r-1) << endl;
        }
    }
}