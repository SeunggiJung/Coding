#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using namespace std;
static int safe;
void bfs(int st, pair<int, int> p, vector<vector<int>>v, vector<vector<bool>> &visited ) {
	queue<pair<int, int>> q;
	int cnt = 0;
	int x = st;
	q.push(p);
	bool flag = false;
	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		if (visited[r][c]) continue;
		visited[r][c] = true;
		int dr[] = { 1,-1,0,0 };
		int dc[] = { 0,0,-1,1 };
		for (int i = 0; i < 4; i++) {
			int xr = r + dr[i];
			int xc = c + dc[i];
			if (xr >= v.size() || xc >= v.size() || xr < 0 || xc < 0 || v[xr][xc] <= x || visited[xr][xc]) continue;
			if (v[xr][xc] > x && !visited[xr][xc]) {
				q.push({ xr,xc });
			}
		}
	}
	safe++;
}
int main() {
	int N;
	cin >> N;
	vector<vector<int>> v(N, vector<int>(N));
	int m = 0;
	int ma = 0;
	int mmm = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> v[i][j];
			ma = max(v[i][j], ma);
		}
	}
	while (m <= ma) {
		vector<vector<bool>>visited(N, vector<bool>(N, false));
		safe = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (v[i][j] > m && !visited[i][j]) {
					bfs(m, { i,j }, v, visited);
				}
			}
		}
		m++;
		mmm = max(safe, mmm);
	}
	
	cout << mmm;
}
