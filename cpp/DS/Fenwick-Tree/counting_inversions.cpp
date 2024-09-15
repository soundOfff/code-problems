// https://codeforces.com/problemset/problem/911/D - Counting Inversions problem

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<bool> vb;
typedef vector<string> vs;

#define fori(i, n) for (int i = 0; i < (n); ++i)
#define fora(i, a, n) for (int i = a; i <= (n); ++i)

const int MAXN = 1500 + 5;

int TREE[MAXN];
int a[MAXN];
int m, n, tot = 0;

void update(int i)
{
    i += 2;
    while (i >= 1)
    {
        TREE[i]++;
        i -= (i & (-i));
    }
}
int query(int i)
{
    i += 2;
    int sum = 0;
    while (i < MAXN)
    {
        sum += TREE[i];
        i += (i & (-i));
    }
    return sum;
}

int main()
{
    // First step traverse the array an mark as visited that position on the tree
    // Second sum all of the positions above the current

    cin >> n;
    fori(i, n)
    {
        cin >> a[i];
        tot += query(a[i]);
        update(a[i]);
    };
    fori(i, n*n) {
        cout << TREE[i];
    }
    cout << endl;
    tot = (tot & 1); // Bitwise operation to determine if the number is odd or even (gets the lsb)
    cin >> m;
    fori(j, m)
    {
        int l, r;
        cin >> l >> r;
        if (l == r)
        {
            if (tot)
            {
                cout << "odd" << endl;
            }
            else
            {
                cout << "even" << endl;
            }
        }
        else
        {
            if ((((r - l + 1) * (r - l)) / 2) & 1)
            {
                tot = 1 - tot;
                if (tot)
                {
                    cout << "odd" << endl;
                }
                else
                {
                    cout << "even" << endl;
                }
            }
            else
            {
                if (tot)
                {
                    cout << "odd" << endl;
                }
                else
                {
                    cout << "even" << endl;
                }
            }
        }
    }
}
