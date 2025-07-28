#include "iostream"
#include <queue>
using namespace std;
void bfs(pair<int,int> in, vector<vector<char>> &c, vector<vector<bool>>&visit, int &cnt) {
	if (!visit[in.first][in.second]) {
		cnt++;
	}
	else return;
	int dr[4] = { 1,-1,0,0 };
	int dc[4] = { 0,0,-1,1 };
	char color;
	queue<pair<int, int>>q;
	q.push(in);
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		visit[x][y] = true;
		color = c[x][y];
		q.pop();
		for (int i = 0; i < 4; i++) {
			int dx = x + dr[i];
			int dy = y + dc[i];
			if (dx >= c.size() || dy >= c.size() || dx < 0 || dy < 0 || visit[dx][dy]) continue;
			if (color == c[dx][dy]) {
				q.push({ dx,dy });
				visit[dx][dy] = true;
			}
		}
	}
}

int main() {
	int N;
	int cnt = 0;
	int cnt_ = 0;
	cin >> N;
	vector<vector<char>>v1(N);
	vector<vector<char>>v2(N);
	vector<vector<bool>>visited1(N);
	vector<vector<bool>>visited2(N);
	for (int i = 0; i < N; i++) {
		v1[i] = vector<char>(N);
		v2[i] = vector<char>(N);
		visited1[i] = vector<bool>(N, false);
		visited2[i] = vector<bool>(N, false);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> v1[i][j];
			if (v1[i][j] == 'G') v2[i][j] = 'R';
			else v2[i][j] = v1[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			bfs({ i,j }, v1, visited1, cnt);
			bfs({ i,j }, v2, visited2, cnt_);
		}
	}
	cout << cnt << "\n" << cnt_;
}