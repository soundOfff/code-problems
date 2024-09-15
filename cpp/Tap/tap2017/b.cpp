#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;

#define fori(i,n) for(int i = 0; i < (n); ++i)
#define fora(i,a,n) for(int i = a; i <= (n); ++i)
#define ford(i,a,n) for(int i = a; i >= 0; --i)
#define pb push_back
#define dprint(v) cout << #v"=" << v << endl //;)
#define int long long

const int MAXN = 1e9 + 3;
const int MOD = 1000000007;

signed main() {
   ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> pirates(n);
    fori(i,n){
        cin >> pirates[i];
    }

    vector<int> cofres(n);
    fori(i,n){
        cin >> cofres[i];
    }
    sort(pirates.begin(), pirates.end(), greater<int>());
    sort(cofres.begin(), cofres.end(), greater<int>());

    ll ans = 1;
    int index = 0;
    fori(i,n) {
        auto p = pirates[i];
        bool bandera = true;
        int l = 0;
        int r = n - 1;
        while(l + 1 < r){
            int mid = (l+r)/2;
            if(p > cofres[mid]){
                l = mid;
            }else{ // t t t f f f f
                r = mid;
            }
        }
         // cofre[r] >

        fora(j, index, n-1) {
            if (p > cofres[j]) {
                bandera = false;
                ans = ans * (j - index);
                ans %= MOD;
                break;
            }
        }
        if(bandera){
            ans = ans * (n - index);
            ans %= MOD;
        }
        cofres[index] = -1;
        index++;
    }
    cout << ans << endl;
    return 0; 
}