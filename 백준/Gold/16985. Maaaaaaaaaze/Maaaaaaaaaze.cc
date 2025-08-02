#include <iostream>

#include <vector>

#include <algorithm>

#include <numeric>

#include <queue>

using namespace std;

typedef pair<int, int> pii;

vector<vector<vector<int>>> board(5, vector<vector<int>>(5, vector<int>(5)));
int dx[] = { 1,-1,0,0,0,0 };
int dy[] = { 0,0,1,-1,0,0 };
int dz[] = { 0,0,0,0,1,-1 };
void rotate(int layer) {
	vector<vector<int>> rotated(5, vector<int>(5));
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			rotated[j][4 - i] = board[layer][i][j];
		}
	}
	board[layer] = rotated;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				cin >> board[i][j][k];
			}
		}
	}
	//4^5 = 1024
	int ans = 126;
	for (int a = 0; a < 4; a++) {
		rotate(0);
		for (int b = 0; b < 4; b++) {
			rotate(1);
			for (int c = 0; c < 4; c++) {
				rotate(2);
				for (int d = 0; d < 4; d++) {
					rotate(3);
					for (int e = 0; e < 4; e++) {
						rotate(4);
						vector<int> permutationIndices(5); // 순열 생성을 위한 인덱스
						iota(permutationIndices.begin(), permutationIndices.end(), 0); // 0, 1, 2, 3, 4로 초기화
						do {
							vector<vector<vector<int>>> current_board;
							for (int index : permutationIndices) {
								current_board.push_back(board[index]);
							}
							if (!current_board[0][0][0] || !current_board[4][4][4]) continue;
							vector<vector<vector<int>>> visited(5, vector<vector<int>>(5, vector<int>(5, 0)));
							queue<vector<int>> q; // x,y,z
							q.push({ 0,0,0 });
							while (!q.empty()) {
								int x = q.front()[0];
								int y = q.front()[1];
								int z = q.front()[2];
								q.pop();
								if (x == 4 && y == 4 && z == 4) {
									ans = min(ans, visited[x][y][z]);
									break;
								}
								for (int i = 0; i < 6; i++) {
									int nx = x + dx[i];
									int ny = y + dy[i];
									int nz = z + dz[i];
									if (nx < 0 || ny < 0 || nz < 0 || nx >= 5 || ny >= 5 || nz >= 5) continue;
									if (visited[nx][ny][nz]) continue;
									if (current_board[nx][ny][nz] == 0) continue;
									visited[nx][ny][nz] = visited[x][y][z] + 1;
									q.push({ nx,ny,nz });
								}
							}
						} while (next_permutation(permutationIndices.begin(), permutationIndices.end()));
					}
				}
			}
		}
	}
	if (ans == 126) cout << -1;
	else cout << ans;
}