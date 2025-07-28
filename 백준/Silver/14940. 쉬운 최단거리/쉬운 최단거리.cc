#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <sstream>
#include <math.h>
using namespace std;
static long long int N, M,K;
static vector<vector<int>> v;
static vector<bool> visited1;
static vector<bool> visited2;
static vector<vector<bool>> visited;
static vector<int> out;
static vector<bool> kn;
static int cnt;
struct compare {
    bool operator()(const pair<pair<int, int>, int>& a, const pair<pair<int, int>, int>& b) {
        return a.second > b.second;
    }
};
void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({ x,y });
    visited[x][y] = true;
    int dr[] = { 1,-1,0,0 };
    int dc[] = { 0,0,-1,1 };
    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr < 0 || nc < 0 || nr >= N || nc >= M || v[nr][nc] == 0 || visited[nr][nc]) continue;
            q.push({ nr,nc });
            visited[nr][nc] = true;
            v[nr][nc] = v[r][c] + 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    v = vector <vector<int>>(N, vector<int>(M));
    visited = vector<vector< bool>>(N, vector<bool>(M, false));
    int x, y = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> v[i][j];
            if (v[i][j] == 2) {
                x = i;
                y = j;
            }
        }
    }
    bfs(x,y);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (v[i][j])
                cout << v[i][j] - 2 << " ";
            else
                cout << v[i][j] << " ";
        }
        cout << "\n";
    }
}
