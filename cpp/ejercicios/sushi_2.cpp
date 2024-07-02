#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

bool is_valid(std::string s)
{
    int left = 0;
    int right = s.size() - 1;

    while (left < right)
    {
        if (
            (s[left] == '2' && s[right] == '1') ||
            (s[left] == '1' && s[right] == '2'))
        {
            return false;
        }
        ++left;
        --right;
    }

    return true;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    string s;
    getline(cin, s);
    s.erase(remove_if(s.begin(), s.end(), ::isspace), s.end());
    int max_len = 1;
    std::string max_str = s.substr(0, 2);

    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            if (j - i > max_len && (j - i) % 2 == 0 && is_valid(s.substr(i, j - i)))
            {
                max_len = j - i;
                max_str = s.substr(i, j - i);
            }
        }
    }
    cout << max_len << '\n';
    cout << max_str << '\n';
}
