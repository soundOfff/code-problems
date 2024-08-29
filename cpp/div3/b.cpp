#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<string> matrix(n);
        vector<string> ans(n / k, string(n / k, '0'));

        for (int i = 0; i < n; ++i)
        {
            cin >> matrix[i];
        }

        for (int i = 0; i < n / k; ++i)
        {
            for (int j = 0; j < n / k; ++j)
            {
                ans[i][j] = matrix[i * k][j * k];
            }
        }

        for (int i = 0; i < n / k; ++i)
        {
            cout << ans[i] << endl;
        }
    }
    return 0;
}
