#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<bool> vb;

#define fori(i, n) for (int i = 0; i < (n); ++i)
#define fora(i, a, n) for (int i = a; i <= (n); ++i)
#define ford(i, a, n) for (int i = a; i >= (n); --i)

const int MAXN = 2 * 10e9 + 10;

ll calc(ll number)
{
    if (number == 0)
        return 1;
    if (number < 10)
        return number;

    ll calc1 = calc(number / 10); // obtain the last num
    ll calc2 = calc(number / 10 - 1);

    return max(number % 10 * calc1, 9 * calc2); // If the last digit is 0 get the max of number - 1
}

int main()
{
    ll n;
    cin >> n;
    cout << calc(n) << endl;
}
