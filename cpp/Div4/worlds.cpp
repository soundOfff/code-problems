
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

#define ll long long

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string a, b;
        char aux;
        cin >> a >> b;
        aux = a[0];
        a[0] = b[0];
        b[0] = aux;
        cout << a << " " << b << endl;
    }
}