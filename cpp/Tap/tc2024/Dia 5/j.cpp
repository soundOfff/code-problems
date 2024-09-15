#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ii> vp;
typedef vector<long long int> vll;
typedef vector<char> vc;
typedef long double ld;

#define fori(i, n) for (int i = 0; i < (n); ++i)
#define fora(i, a, n) for (int i = a; i <= (n); ++i)
#define ford(i, a, n) for (int i = a; i >= (n); --i)

int ROWS, COLS;
vector<string> matrix;
vector<bool> visited(2005, false);

bool go(int row, int col)
{
    if (row >= ROWS && col >= COLS)
    {
        return true;
    }
    if (row >= ROWS || col >= COLS)
    {
    }
    if (matrix[row][col] == '*') // check this
    {
        return go(row + 1, col);
    }
    if (matrix[row + 1][col] == '*' && matrix[row][col + 1] == '.')
    {
        matrix[row][col] = '^';
        matrix[row][col + 1] = 'v';
    }
    if (matrix[row + 1][col] == '.' && matrix[row][col + 1] == '*')
    {
        matrix[row][col] = '<';
        matrix[row + 1][col] = '>';
    }

    // multiple ways to fill but not all of them correctly
    // if (matrix[row + 1][col] == '.' && matrix[row][col + 1] == '.')
    // {
    // }
}

int main()
{
    cin >> ROWS >> COLS;
    matrix.resize(ROWS);
    fori(i, ROWS)
    {
        string str;
        cin >> str;
        matrix.push_back(str);
    }

    // cycles ?

    // valid ?
    bool isValid = go(0, 0);
    cout << isValid << endl;
}