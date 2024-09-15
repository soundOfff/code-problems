#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

const int MAXN = 10e6 + 3;

#define fori(i, n) for (int i = 0; i < (n); ++i)
#define fora(i, a, n) for (int i = a; i <= (n); ++i)
#define ford(i, a, n) for (int i = a; i >= (n); --i)

#include "iostream"
#include "vector"
#include "algorithm"

int count_ab(string str, deque<int> &a) {
    int c = 0;
    fori(i, int(str.length())-1) {
        if (str[i] == 'a' && str[i+1] == 'b') {
            c++;
            a.push_back(i);
        };
    }
    return c;
}

int count_ba(string str, deque<int> &a) {
    int c = 0;
    fori(i, int(str.length())-1) {
        if (str[i] == 'b' && str[i+1] == 'a') {
            c++;
            a.push_back(i);
        };
    }
    return c;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        deque<int> ab_i;
        deque<int> ba_i;
        int ab = count_ab(str, ab_i);
        int ba = count_ba(str, ba_i);
        int op=0;
        while (ab != ba)
        {
            if (ab > ba) {
                int index = ab_i[0];
                ab_i.pop_front();
                str[index] = 'b';
            } else {
                int index = ab_i[0];
                ab_i.pop_front();
                str[index] = 'a';
            }
            ab = count_ab(str, ab_i);
            ba = count_ba(str, ba_i);
            op++;
        }

        cout << str << endl;
    }
    
    return 0;
}