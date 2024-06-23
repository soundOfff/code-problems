#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, k, blocks = 0;
        cin >> n >> k;
        
        int curr = 1;

        if (k == 0) {
            int res = n - 1;
            cout << res << '\n';
        } else {
            for (int j = 0; j < k; j++) {
                int li, ri;
                cin >> li >> ri;
                
                if (curr < li) {
                    blocks += li - curr;
                    curr = li;
                }
                if (curr >= li) {
                    curr = ri;
                }
            }
            if (curr < n) {
                blocks += n - curr;
            }
            cout << blocks << '\n';
        }
    }
    return 0;
}
