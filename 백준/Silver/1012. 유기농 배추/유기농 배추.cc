#include <iostream>
#include <queue>
#include <vector>
using namespace std;
static queue<vector<vector<int>>> ps;
static queue<queue<int>> ins;
static bool flag = true;
static queue<pair<int, int>> q;
static int cnt;
void bfs(vector<vector<int>> &p, pair<int, int> in) {
	int dr[4] = { 1,-1,0,0 };
	int dc[4] = { 0,0,-1,1 };
	int x, y;
	flag = false;

	q.push(in);

	while (!q.empty()) {
		x = q.front().first; y = q.front().second;
		for (int i = 0; i < 4; i++) {
			int nr = x + dr[i];
			int nc = y + dc[i];
			if (nr >= p.size() || nr < 0 || nc >= p[0].size() || nc < 0) continue;
			if (p[nr][nc] == 1) {
				pair<int, int> qq = make_pair(nr, nc);
				q.push(qq);
				p[nr][nc] = 0;
			}
		}
		q.pop();
	}
}

int main() {
	int T;
	cin >> T;
	int* K = new int[T];
	queue<queue<pair<int, int>>> qu;
	for (int i = 0; i < T; i++) {
		int M, N;
		cin >> M >> N >> K[i];
		vector<vector<int>> invec(M);
		queue<pair<int, int>> in;
		for (int j = 0; j < M; j++)
			invec[j] = vector<int>(N);
		for (int q = 0; q < M; q++) {
			for (int w = 0; w < N; w++) {
				invec[q][w] = 0;
			}
		}
		
		for (int j = 0; j < K[i]; j++) {
			int X, Y;
			cin >> X>> Y;
			invec[X][Y] = 1;
			pair<int, int> i = make_pair(X, Y);
			in.push(i);
		}
		ps.push(invec);
		qu.push(in);
	}
	for (int i = 0; i < T; i++) {
		cnt = 0;
		for (int j = 0; j < K[i]; j++) {

			
			int x, y;
			x = qu.front().front().first;
			y = qu.front().front().second;

			if (ps.front()[x][y] == 1) { 
				cnt++;
				bfs(ps.front(), qu.front().front());
			}
			
			qu.front().pop();
		}
		cout << cnt << "\n";
		ps.pop();
		qu.pop();
	}
}
