#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int n, m;
bool grid[55][55];

bool go(int i, int j){
	if(i==n-1 && j==m-1){
		bool ret = grid[i][j];
		grid[i][j] = 0;
		return ret;
	}
	
	if(j==m-1){
		bool ret = grid[i][j] + go(i+1, j);
		grid[i][j] = 0;
		return ret;
	}
	if(i==n-1){
		bool ret = grid[i][j] + go(i, j+1);	
		grid[i][j] = 0;
		return ret;
	}
	
	int jj = j;
	while(grid[i][j]==0 && j+1 < m){
		j++;
	}
	
	if(!grid[i][j]){
		return go(i+1, jj);	
	}
	
	grid[i][j] = 0;
	bool ret = true + go(i, j);
	return ret;
}

int main() {
    cin >> n >> m;
	for(int i = 0; i < n; i++)
	for(int j = 0; j < m; j++){
		cin >> grid[i][j];
	}
	
	int ans = 0;
	while(go(0, 0)){
		ans++;
	}
	
	cout << ans << endl;
}