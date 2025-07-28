#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <string>
#include <map>;
using namespace std;
static int N;
vector<vector<int>> board;
vector<vector<int>> visited;
int cnt=0;
int dr[] = { 1,-1,0,0 };
int dc[] = { 0,0,-1,1 };
int mini = INT32_MAX;
void bfs(int x, int y) {
    cnt++;
    queue<pair<int, int>> q;
    q.push({ x,y });
    visited[x][y] = cnt;
    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr < 0 || nc < 0 || nr >= N || nc >= N || visited[nr][nc]) continue;
            if (!board[nr][nc]) continue;
            q.push({ nr,nc });
            visited[nr][nc] = cnt;
        }
    }
}
void bfs2(int x, int y) {
    vector<vector<int>> visit(N, vector<int>(N,0));
    queue<pair<int, int>> q;
    q.push({ x,y });
    visit[x][y] = 1;
    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr < 0 || nc < 0 || nr >= N || nc >= N || visit[nr][nc])continue;
            if (visited[nr][nc] && visited[nr][nc] != visited[x][y]) {
                mini = min(visit[r][c] - 1, mini);
                return;
            }
            if (board[nr][nc]) continue;
            visit[nr][nc] = visit[r][c] + 1;
            q.push({ nr,nc });
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    board = vector<vector<int>>(N, vector<int>(N));
    visited = vector<vector<int>>(N, vector<int>(N,0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j]||!board[i][j]) continue;
            bfs(i, j);
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!board[i][j]) continue;
            bfs2(i, j);
        }
    }
    cout << mini;
}
