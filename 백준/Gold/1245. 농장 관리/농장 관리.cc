#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
int N, M;
vector<vector<int>> board;
vector<vector<bool>> visited;
int cnt = 0;
int dr[] = { 1,-1,0,0,1,1,-1,-1 };
int dc[] = { 0,0,-1,1,1,-1,1,-1 };
void bfs(pii start) {
    cnt++;
    queue<pii> q;
    q.push(start);
    visited[start.first][start.second] = true;
    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        int height = board[r][c];
        for (int i = 0; i < 8; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr < 0 || nc < 0 || nr >= N || nc >= M) continue;
            if (visited[nr][nc]) continue;
            if (!board[nr][nc] || board[nr][nc] > height) continue;
            q.push({ nr,nc });
            visited[nr][nc] = true;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    board = vector<vector<int>>(N, vector<int>(M));
    visited = vector<vector<bool>>(N, vector<bool>(M, false));
    priority_queue<vector<int>, vector<vector<int>>> pq;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            pq.push({ board[i][j], i, j });
        }
    }
    while (!pq.empty()) {
        int height = pq.top()[0];
        int r = pq.top()[1];
        int c = pq.top()[2];
        pq.pop();
        if (height == 0) break;
        if (visited[r][c]) continue;
        bfs({ r,c });
    }
    cout << cnt;
}