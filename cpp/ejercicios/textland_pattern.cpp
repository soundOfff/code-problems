#include <bits/stdc++.h>

using namespace std;


int main() {
    int n; string s;
    cin >> n; cin >> s;
    unordered_set <string> hash;
    
    for (int len = 1; len < n; len++) {
        for (int i = 0; i < n - len; i++) {
            hash.insert(s.substr(i, len));
        }
    }

    for (const string& substring : hash) {
        cout << substring << endl;
    }
}