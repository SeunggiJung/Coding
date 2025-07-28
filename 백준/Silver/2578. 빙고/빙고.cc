#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using namespace std;
int main() {
	vector<vector<int>> v(5, vector<int>(5));
	vector<vector<int>> visited(5, vector<int>(5, 0));
	queue<int> in;
	map<int, pair<int, int>> jwapyo;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> v[i][j];
			jwapyo[v[i][j]] = { i,j };
		}
	}
	for (int i = 0; i < 25; i++) {
		int call;
		cin >> call;
		in.push(call);
	}
	int bingo = 0;
	int cnt = 0;
	while (bingo<3) {
		int shj = in.front(); in.pop();
		int r = jwapyo[shj].first;
		int c = jwapyo[shj].second;
		visited[r][c] = 1;
		if (r == c) {
			if (visited[0][0] && visited[1][1] && visited[2][2] && visited[3][3] && visited[4][4])
				bingo++;
		}
		if (visited[r][0] && visited[r][1] && visited[r][2] && visited[r][3] && visited[r][4]) bingo++;
		if (visited[0][c] && visited[1][c] && visited[2][c] && visited[3][c] && visited[4][c]) bingo++;
		if (r + c == 4 && visited[0][4] && visited[1][3] && visited[2][2] && visited[3][1] && visited[4][0]) bingo++;
		cnt++;
	}
	cout << cnt;
}
