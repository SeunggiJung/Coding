#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
int func(vector<vector<int>> v, pair<int,int> start, pair<int,int> end) {
	int sum = 0;
	for (int i = start.first; i <= end.first; i++) {
		for (int j = start.second; j <= end.second; j++) {
			sum += v[i][j];
		}
	}
	return sum;
}
int main() {
	int N, M, K;
	cin >> N >> M;
	vector<vector<int>> nm(N);
	for (int i = 0; i < N; i++) {
		nm[i] = vector<int>(M);
		for (int j = 0; j < M; j++) {
			cin >> nm[i][j];
		}
	}
	cin >> K;
	vector<vector<int>> v(K);
	for (int i = 0; i < K; i++) {
		v[i] = vector<int>(4);
		for (int j = 0; j < 4; j++) {
			cin >> v[i][j];
			v[i][j]--;
		}
	}
	for (int i = 0; i < K; i++) {
		cout << func(nm, { v[i][0], v[i][1] }, { v[i][2], v[i][3] }) << "\n";
	}
}