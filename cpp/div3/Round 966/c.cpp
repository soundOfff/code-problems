#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int m;
        cin >> m;
        for (int i = 0; i < m; ++i) {
            string s;
            cin >> s;

            if (s.length() != n) {
                cout << "NO" << endl;
                continue;
            }

            unordered_map<int, char> numToChar;
            unordered_map<char, int> charToNum;
            bool match = true;

            for (int j = 0; j < n; ++j) {
                int num = a[j];
                char ch = s[j];

                if (numToChar.count(num) && numToChar[num] != ch) {
                    match = false;
                    break;
                }

                if (charToNum.count(ch) && charToNum[ch] != num) {
                    match = false;
                    break;
                }

                numToChar[num] = ch;
                charToNum[ch] = num;
            }

            if (match) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}
