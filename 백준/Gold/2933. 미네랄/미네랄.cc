#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using namespace std;
typedef pair<int, int> pii;
int N, M;
int dr[] = { 1,-1,0,0 };
int dc[] = { 0,0,-1,1 };
vector<vector<char>> board;
vector<vector<bool>> visited;
void gravity(vector<pii> cluster) {
    int mini = INT32_MAX;
    for (auto x : cluster) {
        int cnt = 0;
        while (true) {
            if (x.first + cnt + 1 == N) {
                break;
            }
            if (board[x.first + cnt + 1][x.second] == 'x' && visited[x.first + cnt + 1][x.second]) break;
            cnt++;
        }
        if (cnt) mini = min(mini, cnt);
    }
    for (auto x : cluster) {
        board[x.first + mini][x.second] = 'x';
    }
}
void bfs(int r, int c) {
    queue<pair<int, int>> q;
    q.push({ r,c });
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (visited[x][y]) continue;
        visited[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int nr = x + dr[i];
            int nc = y + dc[i];
            if (nr < 0 || nc < 0 || nr >= N || nc >= M) continue;
            if (visited[nr][nc] || board[nr][nc] == '.') continue;
            q.push({ nr,nc });
        }
    }
}
void find_cluster() {
    
    for (int i = 0; i < M; i++) {
        if (!visited[N - 1][i] && board[N - 1][i] == 'x') bfs(N-1, i);
    }
    vector<pii> clusters;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 'x' && !visited[i][j]) {
                board[i][j] = '.';
                clusters.push_back({ i,j });
            }
        }
    }
    if(clusters.size()) gravity(clusters);
    
}
void th(int height, int dir) {
    visited = vector<vector<bool>>(N, vector<bool>(M, false));
    if (dir % 2 == 0) {
        for (int i = 0; i < M; i++) {
            if (board[height][i] == 'x') {
                board[height][i] = '.';
                break;
            }
        }
    }
    else {
        for (int i = M - 1; i >= 0; i--) {
            if (board[height][i] == 'x') {
                board[height][i] = '.';
                break;
            }
        }
    }
    find_cluster();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    board = vector<vector<char>>(N, vector<char>(M));
    visited = vector<vector<bool>>(N, vector<bool>(M, false));
    for (int i = 0; i < N; i++) {
        string in;
        cin >> in;
        for (int j = 0; j < in.length(); j++) board[i][j] = in[j];
    }
    int T;
    cin >> T;
    vector<int> throwing(T);
    for (int i = 0; i < T; i++) {
        cin >> throwing[i];
        th(N-throwing[i], i);
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << board[i][j];
        }
        cout << "\n";
    }
}