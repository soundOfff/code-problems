#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int gcd(int a, int b) { if (b == 0) return a; return gcd(b, a%b); } 

int main() {
    long long N, M;
    cin >> N >> M;

    vector<vector<int>> mat(M, vector<int>(M, 0));
    for (int i = 1; i <= M; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (gcd(i, j) == 1) {
                mat[i-1][j-1] = 1;
            }
        }
    }
    
}