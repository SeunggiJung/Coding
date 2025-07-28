#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
static int danji;
static vector<vector<int>> map;
static vector<vector<bool>> visited;
int func(pair<int, int> where) {
	int d = danji; // 단지 번호 부여
	int count = 1; // 단지내 집 수
	danji++;
	queue<pair<int, int>> qu;
	qu.push(where);
	while (!qu.empty()) {
		pair<int, int> rc = qu.front();
		qu.pop();
		int dr[] = { 1,-1,0,0 };
		int dc[] = { 0,0,-1,1 };
		for (int i = 0; i < 4; i++) {
			int rd = rc.first + dr[i];
			int cd = rc.second + dc[i];
			if (rd<0 || rd>=map.size() || cd<0 || cd>=map.size() || visited[rd][cd]) continue;
			if (map[rd][cd]) {
				map[rd][cd] = d;
				qu.push({ rd,cd });
				visited[rd][cd] = true;
				count++;
			}
		}
	}
	return count;
}
int main() {
	danji = 1;
	int N;
	cin >> N;
	map = vector<vector<int>>(N, vector<int>(N));
	visited = vector<vector<bool>>(N, vector<bool>(N, false));
	queue<pair<int, int>> q;

	for (int i = 0; i < N; i++) {
		string in;
		cin >> in;
		for (int j = 0; j < N; j++) {
			map[i][j] = in[j] - '0';
			if (in[j]=='1') {
				q.push({ i,j});
			}
		}
	}
	vector<int> result;
	while (!q.empty()) {
		if (!map[q.front().first][q.front().second] || visited[q.front().first][q.front().second]) {
			q.pop(); 
			continue;
		}
		visited[q.front().first][q.front().second] = true;
		result.push_back(func(q.front()));
		q.pop();		
	}
	cout << danji-1 << "\n";
	sort(result.begin(), result.end());
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << "\n";
	}
}
