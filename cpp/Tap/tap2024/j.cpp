#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

#define fori(i, n) for (int i = 0; i < (n); ++i)
#define pb push_back

int n, x;
vi a;

int find2Swap(int i)
{
    int index = -1;
    fori(j, n)
    {
        if (j == i || a[j] == a[i])
            continue;
        if (i == 0)
        {
            if ((a[j - 1] + a[i] != x && a[j + 1] + a[i] != x) && a[j] + a[i + 1] != x)
            {
                index = j;
                break;
            }
        }
        if (j == 0)
        {
            if (a[j + 1] + a[i] != x && a[j] + a[i + 1] != x)
            {
                index = j;
                break;
            }
        }
        else
        {
            if ((a[j - 1] + a[i] != x && a[j + 1] + a[i] != x) && (a[j] + a[i - 1] != x && a[j] + a[i + 1] != x))
            {
                index = j;
                break;
            }
        }
    }
    return index;
}

int main()
{
    cin >> n >> x;
    a.resize(n);

    fori(i, n)
    {
        cin >> a[i];
    }

    bool flag = true;
    fori(i, n - 1)
    {
        if (a[i] + a[i + 1] == x)
        {
            int j = find2Swap(i);
            if (j == -1)
            {
                flag = false;
                break;
            }
            swap(a[i], a[j]);
        }
    }

    if (flag)
    {
        fori(i, n - 1)
        {
            if (a[i] + a[i + 1] == x)
            {
                flag = false;
                break;
            }
        }
    }

    if (flag)
    {
        fori(i, n)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "*" << endl;
    }

    return 0;
}