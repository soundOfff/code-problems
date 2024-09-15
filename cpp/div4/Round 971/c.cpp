#include <iostream>
using namespace std;

#define ll long long

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll x, y, k;
        cin >> x >> y >> k;

        ll dx = (x + k - 1) / k;  
        ll dy = (y + k - 1) / k;  
        
        ll moves = max(dx*2-1,dy*2);

        cout << moves << endl;
    }
    return 0;
}
