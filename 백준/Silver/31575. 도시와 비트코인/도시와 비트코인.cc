#include <iostream>
#include <queue>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int N, M;
	cin >> N >> M;
	vector<vector<int>> v(M, vector<int>(N));
	queue<pair<int, int>> q;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin>>v[i][j];
		}
	}
	q.push({ 0,0 });
	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
        if (r == v.size() - 1 && c == v[0].size() - 1 && v[r][c]) {
				cout << "Yes";
				return 0;
			}
		if (!v[r][c])continue;
		v[r][c] = 0;
		int dr[] = { 1,0 };
		int dc[] = { 0,1 };
		for (int i = 0; i < 2; i++) {
			int xr = r + dr[i];
			int xc = c + dc[i];
			if (xr >= v.size() || xc >= v[0].size() || !v[xr][xc]) continue;
			q.push({ xr,xc });
		}
	}
	cout << "No";
}