#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <sstream>
#include <math.h>
using namespace std;
static long long int N, M,K;
static vector<vector<char>> v;
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
    int dr[] = { 1,-1,0,0 };
    int dc[] = { 0,0,-1,1 };
    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        if (v[r][c] == 'P') cnt++;
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr < 0 || nc < 0 || nr >= N || nc >= M || visited[nr][nc] || v[nr][nc] == 'X')continue;
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
    v = vector<vector<char>>(N, vector<char>(M));
    visited = vector<vector<bool>>(N, vector<bool>(M, false));
    int x=0, y=0;
    cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> v[i][j];
            if (v[i][j] == 'I') {
                x = i;
                y = j;
                visited[i][j] = true;
            }
        }
    }
    bfs(x, y);
    if (cnt) cout << cnt;
    else cout << "TT";
}
