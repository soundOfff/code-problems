#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;

#define fori(i,n) for(int i = 0; i < (n); ++i)
#define fora(i,a,n) for(int i = a; u <= (n); ++i)
#define ford(i,a,n) for(int i = a; i >= 0; --i)
#define pb push_back
#define dprint(v) cout << #v"=" << v << endl //;)

const int MAXN = 1e6 + 3;

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    map<int,string> mapinho;
    // mapinho[0] = "DO";
    // mapinho[1] = "DO#";
    // mapinho[2] = "RE";
    // mapinho[3] = "RE#";
    // mapinho[4] = 
    // mapinho[5]
    // mapinho[6]
    // mapinho[7]
    // mapinho[8]
    // mapinho[9]
    // mapinho[10]
    // mapinho[11]
    // mapinho[12]

    vector<string> notas = {"DO","DO#", "RE","RE#","MI","FA", "FA#", "SOL","SOL#", "LA", "LA#", "SI"};

    int n;
    string s;
    int mod = 12;

    int index= 0;
    fori(i,12){
        if(notas[i] == s){
            index = (i - n)%mod; 
        }
    }
        
    cout << notas[index] << endl;
    return 0; 
}