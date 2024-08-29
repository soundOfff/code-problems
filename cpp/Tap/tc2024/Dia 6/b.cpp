#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<bool> vb;

#define fori(i, n) for (int i = 0; i < (n); ++i)

const int MAXN = 10e6 + 4;

int main()
{
    char card_n;
    char card_t;
    cin >> card_n >> card_t;
    bool play = false;
    fori(i, 5)
    {
        char ni, ti;
        cin >> ni >> ti;
        if (card_n == ni || card_t == ti)
        {
            play = true;
        }
    }

    cout << (play ? "YES" : "NO") << endl;
}