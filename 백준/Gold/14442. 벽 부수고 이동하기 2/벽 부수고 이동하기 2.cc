#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
static int N, M, K;
vector<vector<int>> v;
vector<vector<vector<int>>> visited;
static int mini;
bool flag = false;
void bfs() {
    queue<vector<int>> q;
    q.push({ 0,0,K });
    v[0][0] = 1;
    visited[K][0][0] = 1;
       
    int dr[] = { 1,-1,0,0 };
    int dc[] = { 0,0,-1,1 };
    while (!q.empty()) {
        int r = q.front()[0];
        int c = q.front()[1];
        int b = q.front()[2];
        q.pop();
        if (r == N - 1 && c == M - 1) {
            flag = true;
            mini = min(mini, visited[b][r][c]);
            break;
        }
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr < 0 || nc < 0 || nr >= N || nc >= M) continue;
            if (visited[b][nr][nc]) continue;
            if (v[nr][nc] == -1 && b > 0 && !visited[b - 1][nr][nc]) {
                visited[b - 1][nr][nc] = visited[b][r][c] + 1;
                q.push({ nr,nc,b - 1 });
            }
            else if (!v[nr][nc] && !visited[b][nr][nc]) {
                visited[b][nr][nc] = 1 + visited[b][r][c];
                q.push({ nr,nc,b });
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    mini = 999999999;
    cin >> N >> M >> K;
    v = vector<vector<int>>(N, vector<int>(M));
    visited = vector<vector<vector<int>>>(K + 1, vector < vector<int>>(N, vector<int>(M, 0)));
    for (int i = 0; i < N; i++) {
        string in;
        cin >> in;
        for (int j = 0; j < M; j++) {
            v[i][j] = in[j]-'0';
            if (v[i][j] == 1) v[i][j] = -1;
        }
    }
    bfs();
    if (flag)
        cout << mini;
    else cout << -1;
}