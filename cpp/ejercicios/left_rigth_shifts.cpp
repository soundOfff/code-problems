#include <bits/stdc++.h>

using namespace std;

const int MIN = 97; // a ASCII value
const int MAX = 122; // z ASCII value
const int DIFF = 25;
const int MIDDLE = (122 + 97) / 2;

int left_shift(int a) {
    if ( a - 1 < MIN) {
        return MAX;
    }
    return a - 1;
}

int right_shift(int a) {
    if (a + 1 > MAX) {
        return MIN;
    }
    return a + 1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n, k;
        string str;
        cin >> n >> k >> str;
        for (int j = 0; j < n && k > 0; j++)
        {
            int ch = int(str[j]); // ASCII value
            if (ch > MIDDLE) {
                while (ch != MIN  && k > 0) // TODO: change this whiles
                {
                    ch = right_shift(ch);
                    k--;
                } 
            } else {
                while (ch != MIN  && k > 0) {
                    ch = left_shift(ch);
                    k--;
                }
            }
            // If we're at the last character and still have tries
            if (k > 0) {
            for (int j = n - 1; j >= 0 && k > 0; j--) {
                str[j] = k % 2 == 0 ? 'a' : 'b';
                break;
            }
        }
            str[j] = char(ch);
        }
        cout << str << '\n';
    }
}