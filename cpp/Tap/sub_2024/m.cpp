#include <bits/stdc++.h>

using namespace std;

#define fori(i, n) for (int i = 0; i < (n); ++i)
#define fora(i, a, n) for (int i = a; i <= (n); ++i)
#define ford(i, a, n) for (int i = a; i >= (n); --i)

#define pb push_back

const int MAXN = 105;

int N;

queue<int> q;
bool visited[MAXN];
int dist[MAXN];

// int get_max(int source)
// {
//     // return max_element(&M[source][0], &M[source][0] + N) - &M[source][0];
//     return max_element(&M[source][1], &M[source][1] + N) - &M[source][0];
// }

int floyd(vector<vector<int>> &dist)
{
    int ans = 0;
    vector<vector<int>> ch(N, vector<int>(N));
    fori(k, N)
    {
        fori(u, N)
        {
            fori(v, N)
            {
                int scale_dist = dist[u][k] + dist[k][v]; // scale dist
                if (dist[u][v] >= scale_dist && u != v && u != k && k != v)
                {
                    if (dist[u][v] > scale_dist) // direct path gtr scale dist
                    {
                        return -1;
                    }
                    dist[u][v] = scale_dist; // updates the shortest distance u,v
                    if (ch[u][v] == 0)
                        ans++;
                    ch[u][v]++; // track of each short distance update
                }
            }
        }
    }
    return ans;
}

int main()
{
    cin >> N;
    vector<vector<int>> graph(N, vector<int>(N));

    fori(i, N)
    {
        fori(j, N)
        {
            int c;
            cin >> c;
            graph[i][j] = c;
        }
    }

    int ans = floyd(graph);

    cout << (ans > 0 ? ans / 2 : ans) << endl;
}