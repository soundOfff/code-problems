#include <bits/stdc++.h>

using namespace std;



int main() {
    int t;
    cin >> t;
    string W = "LUDDYROCKS";
    int size = 10;
    for (int i = 0; i < t; i++)
    {
        int n;
        string s;
        cin >> n;
        cin >> s;
        if (n < size)
        {
            cout << "NO" << '\n';
            continue;
        }
        bool flag = true;
        for (int j = 0; j < size; j++)
        {
            if (s.find(W[j]) == string::npos)
            {
                flag = false;
                break;
            }
        }
         if (flag) {
            cout << "YES" << '\n';
        }
        else {
            cout << "NO" << '\n';
        }
    }
}