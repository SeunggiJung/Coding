#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
int N, M;
int dr[] = { 1,-1,0,0 };
int dc[] = { 0,0,-1,1 };
vector<int> result; // 크기, 무지개, 행, 열
vector<pii> rcs;
vector<vector<int>> board;
vector<vector<bool>> visited;
vector<bool> color_check;
int check = 0;
bool bfs(int r, int c, int color) {
    vector<vector<bool>> rv = vector <vector<bool>>(N + 1, vector <bool>(N + 1, false));
    int rainbow = 0;
    int cnt = 0;
    vector<pii> rc;
    queue<pii> q;
    q.push({ r,c });
    visited[r][c] = true;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        cnt++;
        rc.push_back({ x,y });
        for (int i = 0; i < 4; i++) {
            int nr = x + dr[i];
            int nc = y + dc[i];
            if (nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
            if (visited[nr][nc]) continue;
            if (board[nr][nc] != 0 && board[nr][nc] != color) continue;
            if (board[nr][nc] == 0) {
                if (rv[nr][nc]) continue;
                rainbow++;
                rv[nr][nc] = true;
            }
            q.push({ nr,nc });
            visited[nr][nc] = true;
            if (board[nr][nc] == 0) visited[nr][nc] = false;
        }
    }
    vector<int> res = { cnt,rainbow, r,c };
    if (cnt < 2 || cnt == rainbow) return false;
    if (res > result) {
        result = res;
        rcs = rc;
        check = color;
    }
    return true;
}
void gravity() {
    for (int i = 0; i < N; i++) {
        for (int j = N - 1; j > 0; j--) {
            if (board[j][i] == -2) {
                for (int k = j - 1; k >= 0; k--) {
                    if (board[k][i] == -1) {
                        j = k;
                        break;
                    }
                    if (board[k][i] == -2) continue;
                    swap(board[k][i], board[j][i]);
                    break;
                }
            }
        }
    }
}
void rotate() {
    vector<vector<int>> copy(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            copy[N - j - 1][i] = board[i][j];
        }
    }
    board = copy;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    board = vector<vector<int>>(N, vector<int>(N));
    visited = vector<vector<bool>>(N, vector<bool>(N, false));
    color_check = vector<bool>(N + 1, false);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
    int ans = 0;
    
    while (true) {
        result = { 0,-1,-1,-1 };
        visited = vector<vector<bool>>(N, vector<bool>(N, false));
        rcs.clear();
        bool flag = false;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (visited[i][j] || board[i][j] <= 0) continue;
                flag |= bfs(i, j, board[i][j]);
            }
        }
        if (!flag) break;
        ans += result[0] * result[0];
        while (!rcs.empty()) {
            board[rcs.back().first][rcs.back().second] = -2;
            rcs.pop_back();
            
        }
        gravity();
        rotate();
        gravity();
        
    }
    cout << ans;
    
}