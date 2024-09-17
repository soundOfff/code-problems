#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 3;

#define fori(i, n) for (int i = 0; i < (n); ++i)
#define fora(i, a, n) for (int i = a; i <= (n); ++i)
#define ford(i, a, n) for (int i = a; i >= (n); --i)

#define pb push_back
string str;
int k;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> str;
    cin >> k;

    int n = str.size();

    // int tries = 0;

    fori(i, n + 1)
    {
        if (i + k >= n)
            break;
        string aux = "";

        for (int j = i; j < n; j += k)
        {
            aux += str[j];
        }

        sort(aux.begin(), aux.end());

        int index = 0;
        for (int ii = i; ii < n; ii += k)
        {
            str[ii] = aux[index];
            index++;
        }
    }

    cout << str << endl;
}