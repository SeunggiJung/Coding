#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
static int N, M;
vector<vector<int>> v;
vector<vector<bool>> visited;
map<pair<int, int>, bool> mark;
int dr[] = { 1,-1,0,0 };
int dc[] = { 0,0,-1,1 };
void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({ x,y });
    visited[x][y] = true;
    int siz = 0;
    vector<pair<int, int>> wall;
    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        siz++;
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr < 0 || nc < 0 || nr >= N || nc >= M || visited[nr][nc]) continue;
            if (mark[{nr,nc}]) {
                wall.push_back({ nr,nc });
                continue;
            }
            visited[nr][nc] = true;
            q.push({ nr,nc });
        }
    }
    sort(wall.begin(), wall.end());
    wall.erase(unique(wall.begin(), wall.end()), wall.end());
    while (!wall.empty()) {
        int r = wall.back().first;
        int c = wall.back().second;
        wall.pop_back();
        v[r][c] += siz;
        v[r][c] %= 10;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    v = vector<vector<int>>(N, vector<int>(M));
    visited = vector<vector<bool>>(N, vector < bool>(M, false));
    queue<pair<int, int>> zeros;
    for (int i = 0; i < N; i++) {
        string in;
        cin >> in;
        for (int j = 0; j < M; j++) {
            v[i][j] = in[j] - '0';
            if (!v[i][j]) zeros.push({ i,j });
            else mark[{i, j}] = true;
        }
    }
    while (!zeros.empty()) {
        int r = zeros.front().first;
        int c = zeros.front().second;
        zeros.pop();
        if (visited[r][c]) continue;
        bfs(r, c);
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << v[i][j];
        }
        cout << "\n";
    }
}